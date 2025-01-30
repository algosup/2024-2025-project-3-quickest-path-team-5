/*!
    \file Api.cpp
    \brief API Code source
    \authors CHARLES Rémy, CARON Maxime
*/

#include "Api.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace api {
    // Simulate quickest path calculation
    std::pair<int, std::vector<int>> calculate_quickest_path(int source, int destination) {
        if (source == destination) {
            return {0, {source}};
        }

        int travel_time = abs(destination - source) * 10;
        std::vector<int> path = {source, (source + destination) / 2, destination};

        return {travel_time, path};
    }

    // Helper function to read files
    std::string read_file(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filepath);
        }
        return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }

    // Function to add CORS headers
    void add_cors_headers(crow::response& res) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Accept, Content-Type");
    }

    // Set up API routes
    void setup_routes(crow::SimpleApp& app) {

        // Serve the consolidated HTML interface
        CROW_ROUTE(app, "/")([]() {
            try {
                std::string html_content = read_file("../src/interface_api/index.html");
                crow::response res(html_content);
                res.add_header("Content-Type", "text/html");
                return res;
            } catch (const std::exception& e) {
                return crow::response(500, "Failed to load interface: " + std::string(e.what()));
            }
        });

        // Route to serve the image
        CROW_ROUTE(app, "/img/logo.png")
        ([]() {
            std::ifstream file("../src/interface_api/img/logo.png", std::ios::binary | std::ios::ate);
            if (!file) {
                return crow::response(404, "Image not found");
            }

            auto size = file.tellg();
            file.seekg(0, std::ios::beg);

            std::vector<char> buffer(size);
            file.read(buffer.data(), size);

            crow::response res;
            res.code = 200;
            res.set_header("Content-Type", "image/png");
            res.body = std::string(buffer.begin(), buffer.end());
            return res;
        });

        // Handle preflight OPTIONS requests for CORS
        CROW_ROUTE(app, "/quickest-path").methods(crow::HTTPMethod::OPTIONS)(
            [](const crow::request& req) {
                (void)req;
                crow::response res;
                add_cors_headers(res);
                res.code = 204;
                return res;
            });

        // Quickest path endpoint using GET with query parameters
        CROW_ROUTE(app, "/quickest-path").methods(crow::HTTPMethod::GET)(
            [](const crow::request& req) {
                crow::response res;

                try {
                    auto query_params = crow::query_string(req.url_params);
                    auto source_param = query_params.get("source");
                    auto destination_param = query_params.get("destination");

                    if (!source_param || !destination_param) {
                        res.code = 400;
                        res.body = "Invalid input: 'source' and 'destination' are required.";
                        add_cors_headers(res);
                        return res;
                    }

                    int source = std::stoi(source_param);
                    int destination = std::stoi(destination_param);

                    if (source <= 0 || destination <= 0) {
                        res.code = 400;
                        res.body = "Invalid source or destination. Must be a positive number.";
                        add_cors_headers(res);
                        return res;
                    }

                    std::string accept_header = req.get_header_value("Accept");

                    std::string format = "json";
                    if (!accept_header.empty()) {
                        if (accept_header.find("application/json") != std::string::npos) {
                            format = "json";
                        } else if (accept_header.find("application/xml") != std::string::npos) {
                            format = "xml";
                        } else {
                            format = "json";
                        }
                    }

                    auto [travel_time, path] = calculate_quickest_path(source, destination);

                    std::string response_content;
                    std::string content_type;

                    if (format == "xml") {
                        std::ostringstream xml_response;
                        xml_response << "<response>";
                        xml_response << "<travel_time>" << travel_time << "</travel_time>";
                        xml_response << "<path>";
                        for (int node : path) {
                            xml_response << "<node>" << node << "</node>";
                        }
                        xml_response << "</path>";
                        xml_response << "</response>";

                        response_content = xml_response.str();
                        content_type = "application/xml";
                    } else {
                        crow::json::wvalue json_response;
                        json_response["travel_time"] = travel_time;
                        json_response["path"] = path;

                        response_content = json_response.dump();
                        content_type = "application/json";
                    }

                    res.body = response_content;
                    res.code = 200;
                    res.add_header("Content-Type", content_type);
                    add_cors_headers(res);
                    return res;
                } catch (const std::exception& e) {
                    res.code = 500;
                    res.body = "An error occurred: " + std::string(e.what());
                    add_cors_headers(res);
                    return res;
                }
            });
    }
}