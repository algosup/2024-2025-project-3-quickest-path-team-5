#ifndef API_H
#define API_H

#include <crow/app.h>
#include <string>

namespace api {
    void setup_routes(crow::SimpleApp& app);

    // Load the graph data from a CSV file
    void load_graph_from_csv(const std::string& filename);

    // Calculate the shortest path between two landmarks
    std::pair<int, std::vector<int>> calculate_shortest_path(int source, int destination);
}

#endif // API_H