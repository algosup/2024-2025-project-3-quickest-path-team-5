/*!
    \file Api.cpp
    \brief API Code source
    \authors CHARLES Rémy, CARON Maxime
*/

#include "../include/Api.hpp"
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
                std::string html_content = read_file("../cap/static/index.html"); // Adjust path as needed
                crow::response res(html_content);
                res.add_header("Content-Type", "text/html");
                return res;
            } catch (const std::exception& e) {
                return crow::response(500, "Failed to load interface: " + std::string(e.what()));
            }
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

                    if (format != "json" && format != "xml") {
                        return crow::response(400, "Invalid format. Must be 'json' or 'xml'.");
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

int main() {
    crow::SimpleApp app;

    // Set up API and routes
    api::setup_routes(app);

    // Start the server
    std::cout << "Starting server on http://localhost:8080" << std::endl;
    app.port(8080).multithreaded().run();

    return 0;
}