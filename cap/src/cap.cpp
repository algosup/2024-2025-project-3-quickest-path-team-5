/*!
    \file Api.cpp
    \brief API Code source
    \authors CHARLES Rémy, CARON Maxime
*/

#include "api/Api.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    crow::SimpleApp app;

    // Set up API and routes
    api::setup_routes(app);

    // Start the server
    std::cout << "Starting server on http://localhost:8080" << std::endl;
    app.port(8080).multithreaded().run();

    return 0;
}