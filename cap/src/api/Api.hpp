/*!
    \file Api.hpp
    \brief API library for the Quickest Path project
    \authors CHARLES Rémy, CARON Maxime
*/

#ifndef API_H
#define API_H

#include "crow_all.h"
#include "../data_struct/Graph.hpp"
#include <cstdint>
#include <string>
#include <vector>
#include <utility> // For std::pair

namespace api {
    /*!
        \brief Set up the API routes for the Crow application.
        \param app The Crow application instance to configure.
    */
    void setup_routes(crow::SimpleApp& app, Graph* graph);

    /*!
        \brief Load the graph data from a CSV file.
        \param filename The path to the CSV file containing the graph data.
        \throws std::runtime_error if the file cannot be opened or parsed.
    */
    void load_graph_from_csv(const std::string& filename);

    /*!
        \brief Calculate the shortest path between two landmarks.
        \param source The starting point of the path.
        \param destination The destination point of the path.
        \return A pair containing the total travel time and the path as a vector of integers.
    */
    std::pair<int, std::vector<uint32_t>> calculate_shortest_path(Graph* graph, uint32_t source, uint32_t destination);

    /*!
        \brief Read a file and return its content as a string.
        \param filepath The path to the file to be read.
        \return The content of the file as a string.
        \throws std::runtime_error if the file cannot be opened.
    */
    std::string read_file(const std::string& filepath);
}

#endif // API_H
