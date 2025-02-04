#include <iostream>
#include <time.h>
#include <cstring>
#include <vector>

#include "graph.hpp"
#include "csv_reader.hpp"
// #include "api/Api.hpp"

#define FILE_PATH "../../data/USA-roads.csv"

using namespace std;

int main()
{
    const char *defaultFilePath = FILE_PATH;
    char buffer[512];
    strcpy(buffer, defaultFilePath);

    cout << "Welcome to CAP" << endl;
    cout << "Enter the path to the dataset file (default: " << defaultFilePath << "): ";
    char input[512];
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n')
    {
        input[strcspn(input, "\n")] = 0; // Remove the newline character
        strcpy(buffer, input);
    }

    if (!checkFileExists(buffer))
    {
        cerr << "File not found: " << buffer << endl;
        exit(EXIT_FAILURE);
    }

    Graph *graph = new Graph();
    clock_t begin = clock();
    loadDataset(graph, buffer);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time spent reading the dataset: " << time_spent << " seconds" << endl;
    cout << "Precomputing landmark distances..." << endl;
    begin = clock();
    graph->addLandmark(23947346);
    graph->addLandmark(9446407);
    graph->addLandmark(4410450);
    graph->addLandmark(19611782);
    graph->addLandmark(1782128);
    graph->addLandmark(9619503);
    graph->addLandmark(1470570);
    graph->addLandmark(12422389);
    graph->addLandmark(689971);
    graph->addLandmark(6232040);
    graph->addLandmark(10375698);
    graph->addLandmark(1352513);
    graph->addLandmark(14911007);
    graph->addLandmark(19560849);
    graph->addLandmark(22382040);
    graph->addLandmark(20794957);
    graph->computeLandmarkDistances();
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time spent precomputing landmark distances: " << time_spent << " seconds" << endl;

    //     crow::SimpleApp app;

    //     // Set up API and routes
    //     api::setup_routes(app);

    //     // Start the server
    //     std::cout << "Starting server on http://localhost:8080" << std::endl;
    //     app.port(8080).multithreaded().run();

    bool running = true;

    while (running)
    {
        // Dijkstra's algorithm
        uint32_t from, to;
        cout << "Enter the source node: ";
        cin >> from;
        cout << "Enter the destination node: ";
        cin >> to;

        begin = clock();
        vector<uint32_t> path = graph->dijkstra(from, to);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        cout << "Shortest path from " << from << " to " << to << " using Dijkstra contains " << path.size() << " nodes:" << endl;
        cout << "Time spent finding the shortest path: " << time_spent << " seconds" << endl;

        begin = clock();
        path = graph->dijkstra(to, from);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        cout << "Shortest reversed path from " << to << " to " << from << " using Dijkstra contains " << path.size() << " nodes:" << endl;
        cout << "Time spent finding the shortest path: " << time_spent << " seconds" << endl;

        begin = clock();
        path = graph->aStarLandmark(from, to);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        cout << "Shortest path from " << from << " to " << to << " using A* landmarks contains " << path.size() << " nodes:" << endl;
        cout << "Time spent finding the shortest path: " << time_spent << " seconds" << endl;

        begin = clock();
        path = graph->aStarLandmark(to, from);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        cout << "Shortest reversed path from " << to << " to " << from << " using A* landmarks contains " << path.size() << " nodes:" << endl;
        cout << "Time spent finding the shortest path: " << time_spent << " seconds" << endl;

        cout << "Do you want to continue? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            running = false;
        }
    }

    return 0;
}