/*!
    \file Api.cpp
    \brief API Code source
    \authors CHARLES Rémy, CARON Maxime
*/

#include "api.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace api {
    // Simulate shortest path calculation
    std::pair<int, std::vector<int>> calculate_shortest_path(int source, int destination) {
        // Mocked calculation logic
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

    // Set up API routes
    void setup_routes(crow::SimpleApp& app) {

        // Serve the consolidated HTML interface
        CROW_ROUTE(app, "/")([]() {
            try {
                std::string html_content = read_file("../src/api/static/index.html");
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
            std::ifstream file("../src/api/static/img/logo.png", std::ios::binary | std::ios::ate);
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


        // Shortest path endpoint with file download support
        CROW_ROUTE(app, "/shortest-path").methods(crow::HTTPMethod::POST)(
            [](const crow::request& req) {
                try {
                    auto body = crow::json::load(req.body);
                    if (!body || !body.has("source") || !body.has("destination") || !body.has("format")) {
                        return crow::response(400, "Invalid input: 'source', 'destination', and 'format' required.");
                    }

                    // Extract request parameters
                    int source = body["source"].i();
                    int destination = body["destination"].i();
                    std::string format = body["format"].s();

                    // Validate format
                    if (format != "json" && format != "xml") {
                        return crow::response(400, "Invalid format. Must be 'json' or 'xml'.");
                    }
                    
                    // Validate input
                    if (source <= 0 || destination <= 0) {
                        return crow::response(400, "Invalid source or destination. Must be a positive number.");
                    }

                    // Calculate shortest path
                    auto [travel_time, path] = calculate_shortest_path(source, destination);

                    // Prepare file content
                    std::string file_content;
                    std::string file_extension;
                    std::string content_type;

                    if (format == "xml") {
                        // Generate XML content
                        std::ostringstream xml_response;
                        xml_response << "<response>";
                        xml_response << "<travel_time>" << travel_time << "</travel_time>";
                        xml_response << "<path>";
                        for (int node : path) {
                            xml_response << "<node>" << node << "</node>";
                        }
                        xml_response << "</path>";
                        xml_response << "</response>";

                        file_content = xml_response.str();
                        file_extension = "xml";
                        content_type = "application/xml";
                    } else {
                        // Generate JSON content
                        crow::json::wvalue json_response;
                        json_response["travel_time"] = travel_time;
                        json_response["path"] = path;

                        file_content = json_response.dump();
                        file_extension = "json";
                        content_type = "application/json";
                    }

                    // Set headers for file download
                    crow::response response(file_content);
                    response.add_header("Content-Type", content_type);
                    response.add_header("Content-Disposition", "attachment; filename=shortest-path." + file_extension);

                    return response;
                } catch (const std::exception& e) {
                    return crow::response(500, "An error occurred: " + std::string(e.what()));
                }
            });
    }
}