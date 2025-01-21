#include "Api.hpp"
#include <crow/app.h>
#include <iostream>

int main() {
    crow::SimpleApp app;

    // Set up API routes
    api::setup_routes(app);

    // Start the server
    std::cout << "Starting server on http://localhost:8080" << std::endl;
    app.port(8080).multithreaded().run();

    return 0;
}