#include <iostream>
#include <time.h>
#include <cstring>
#include <vector>

#include "graph.hpp"
#include "csv_reader.hpp"
#include "api/Api.hpp"

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
    graph->selectLandmarks(16);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time spent precomputing landmark distances: " << time_spent << " seconds" << endl;

    crow::SimpleApp app;

    // Set up API and routes
    api::setup_routes(app, graph);

    // Start the server
    std::cout << "Starting server on http://localhost:8080" << std::endl;
    app.port(8080).multithreaded().run();

    return 0;
}