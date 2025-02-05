/*!
    \file Api.cpp
    \brief API implementation for shortest path calculation
    \authors CHARLES Rémy, CARON Maxime
*/

#include "api.hpp"
#include <crow_all.h>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace api {
    namespace {
        // HTTP status constants
        constexpr int HTTP_OK = 200;
        constexpr int HTTP_BAD_REQUEST = 400;
        constexpr int HTTP_NOT_ACCEPTABLE = 406;
        constexpr int HTTP_INTERNAL_ERROR = 500;

        // Add CORS headers to responses
        void add_cors_headers(crow::response& res) {
            res.add_header("Access-Control-Allow-Origin", "*");
            res.add_header("Access-Control-Allow-Methods", "GET, OPTIONS");
            res.add_header("Access-Control-Allow-Headers", "Accept, Content-Type");
        }

        // Validate and parse node ID parameter
        optional<uint32_t> parse_node_param(const string& param, const string& name, crow::response& res) {
            if (param.empty()) {
                res.code = HTTP_BAD_REQUEST;
                res.body = "Missing parameter: " + name;
                return nullopt;
            }

            try {
                size_t pos;
                auto value = stoul(param, &pos);
                
                if (pos != param.size()) {
                    res.code = HTTP_BAD_REQUEST;
                    res.body = "Invalid " + name + ": contains non-numeric characters";
                    return nullopt;
                }
                return static_cast<uint32_t>(value);
            }
            catch (const exception&) {
                res.code = HTTP_BAD_REQUEST;
                res.body = "Invalid " + name + ": must be a positive integer";
                return nullopt;
            }
        }

        // Generate XML response
        string generate_xml_response(uint64_t travel_time, const vector<uint32_t>& path) {
            ostringstream xml;
            xml << "<response>";
            xml << "<travel_time>" << travel_time << "</travel_time>";
            xml << "<path>";
            for (auto node : path) {
                xml << "<node>" << node << "</node>";
            }
            xml << "</path>";
            xml << "</response>";
            return xml.str();
        }

        // Generate JSON response
        string generate_json_response(uint64_t travel_time, const vector<uint32_t>& path) {
            crow::json::wvalue json;
            json["travel_time"] = travel_time;
            json["path"] = path;
            return json.dump();
        }
    }

    pair<uint64_t, vector<uint32_t>> calculate_quickest_path(Graph* graph, uint32_t source, uint32_t destination) {
        if (!graph || source == destination) {
            return {0, {source}};
        }

        auto path = graph->aStarLandmark(source, destination);
        if (path.empty()) {
            throw runtime_error("No path found between nodes");
        }

        // Calculate actual travel time from path
        uint64_t total_time = 0;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            auto& edges = graph->nodeMap[path[i]]->edges;
            for (const auto& edge : edges) {
                if (edge.destID == path[i+1]) {
                    total_time += edge.time;
                    break;
                }
            }
        }

        return {total_time, path};
    }

    void setup_routes(crow::SimpleApp& app, Graph* graph) {
        // CORS preflight handler
        CROW_ROUTE(app, "/quickest-path")
            .methods(crow::HTTPMethod::OPTIONS)([](const crow::request&) {
                crow::response res;
                add_cors_headers(res);
                res.code = 204;
                return res;
            });

        // Main endpoint handler
        CROW_ROUTE(app, "/quickest-path")
            .methods(crow::HTTPMethod::GET)([graph](const crow::request& req) {
                crow::response res;
                add_cors_headers(res);

                try {
                    // Parse parameters
                    auto source = parse_node_param(req.url_params.get("source"), "source", res);
                    auto destination = parse_node_param(req.url_params.get("destination"), "destination", res);
                    if (!source || !destination) return res;

                    // Validate nodes exist
                    if (!graph->nodeMap[*source] || !graph->nodeMap[*destination]) {
                        res.code = HTTP_BAD_REQUEST;
                        res.body = "Requested nodes do not exist in the graph";
                        return res;
                    }

                    // Determine response format
                    const auto accept = req.get_header_value("Accept");
                    const bool wants_json = accept.find("application/json") != string::npos;
                    const bool wants_xml = accept.find("application/xml") != string::npos;

                    if (!wants_json && !wants_xml && accept != "*/*") {
                        res.code = HTTP_NOT_ACCEPTABLE;
                        res.body = "Supported formats: application/json, application/xml";
                        return res;
                    }

                    // Calculate path
                    auto [travel_time, path] = calculate_quickest_path(graph, *source, *destination);
                    
                    // Generate response
                    if (wants_xml) {
                        res.body = generate_xml_response(travel_time, path);
                        res.set_header("Content-Type", "application/xml");
                    } else {
                        res.body = generate_json_response(travel_time, path);
                        res.set_header("Content-Type", "application/json");
                    }

                    res.code = HTTP_OK;
                }
                catch (const exception& e) {
                    res.code = HTTP_INTERNAL_ERROR;
                    res.body = "Calculation error: " + string(e.what());
                }

                return res;
            });
    }
}