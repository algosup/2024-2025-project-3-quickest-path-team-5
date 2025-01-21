#include <iostream>
#include <time.h>
#include <sys/resource.h> // For memory usage tracking
#include <cstring>
#include <vector>

#include "graph.hpp"
#include "csv_reader.hpp"

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

    struct rusage usage;
    Graph *graph = new Graph();
    clock_t begin = clock();    
    loadDataset(graph, buffer);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time spent reading the dataset: " << time_spent << " seconds" << endl;
    getrusage(RUSAGE_SELF, &usage);
    float memUsage = (float)(usage.ru_maxrss / (1024.0f * 1024.0f)); // Convert to MB
    cout << "Memory usage: " << (int)memUsage << " MB for: " << graph->getNumNodes() << " nodes and " << graph->getNumEdges() << " edges" << endl;

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

    cout << "Shortest path from " << from << " to " << to << " contains " << path.size() << " nodes:" << endl;
    cout << "Path: ";
    for (uint32_t node : path)
    {
        cout << node << "\t";
    }
    cout << endl;
    cout << "Time spent finding the shortest path: " << time_spent << " seconds" << endl;

    begin = clock();
    path = graph->dijkstra(to, from);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "Shortest path from " << to << " to " << from << " contains " << path.size() << " nodes:" << endl;
    cout << "Path: ";
    for (uint32_t node : path)
    {
        cout << node << "\t";
    }
    cout << endl;
    cout << "Time spent finding the shortest path: " << time_spent << " seconds" << endl;

    graph->~Graph();

    return 0;
}