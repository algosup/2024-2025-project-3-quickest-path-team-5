#include "Api.hpp"
#include <crow/json.h>
#include <vector>
#include <string>
#include <iostream>

namespace api {
    // Simulate shortest path calculation
    std::pair<int, std::vector<int>> calculate_shortest_path(int source, int destination) {
        // Mocked calculation logic
        if (source == destination) {
            return {0, {source}};
        }

        // Simulate a path and travel time
        int travel_time = abs(destination - source) * 10; // Example: time proportional to difference
        std::vector<int> path = {source, (source + destination) / 2, destination}; // Example intermediate point

        return {travel_time, path};
    }

    // Set up API routes
    void setup_routes(crow::SimpleApp& app) {
        // Health check route
        CROW_ROUTE(app, "/")([]() {
            return "API is running!";
        });

        // Shortest path route
        CROW_ROUTE(app, "/shortest-path").methods(crow::HTTPMethod::POST)(
            [](const crow::request& req) {
                try {
                    // Parse JSON input from the request body
                    auto body = crow::json::load(req.body);
                    if (!body || !body.has("source") || !body.has("destination")) {
                        return crow::response(400, "Invalid input: 'source' and 'destination' required.");
                    }

                    // Extract source and destination
                    int source = body["source"].i();
                    int destination = body["destination"].i();

                    // Calculate shortest path
                    auto [travel_time, path] = calculate_shortest_path(source, destination);

                    // Prepare the JSON response
                    crow::json::wvalue response;
                    response["travel_time"] = travel_time;
                    response["path"] = path;

                    return crow::response(response);
                } catch (const std::exception& e) {
                    return crow::response(500, "An error occurred: " + std::string(e.what()));
                }
            });
    }
}