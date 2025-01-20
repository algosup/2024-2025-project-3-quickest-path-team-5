#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "csv_reader.h"
#include "mermaid_writter.h"
#include "graphLib.h"

#define FILE_PATH "../../data/USA-roads.csv"
#define MERMAID_FILE "../../data/USA-roads.txt"
#include <sys/resource.h> // For memory usage tracking

int main(void) {
    if(!checkFileExists(FILE_PATH)) {
        fprintf(stderr, "File not found: %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }

    struct rusage usage;
    graph_t* graph = createGraph();
    clock_t begin = clock();    
    readDataset(graph, FILE_PATH);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent reading the dataset: %f seconds\n", time_spent);
    getrusage(RUSAGE_SELF, &usage);
    float memUsage = (float)(usage.ru_maxrss / (1024.0f * 1024.0f)); // Convert to MB
    printf("Memory usage: %d MB\n\n", (int)memUsage);

    begin = clock();    
    if (isDAG(graph)) {
        printf("The graph is a Directed Acyclic Graph (DAG).\n");
    } else {
        printf("The graph is not a DAG.\n");
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent checking for cycles: %f seconds\n", time_spent);
    memUsage = (float)(usage.ru_maxrss / (1024.0f * 1024.0f)); // Convert to MB
    printf("Memory usage: %d MB\n\n", (int)memUsage);

    begin = clock();    
    if (areAllNodesAccessible(graph)) {
        printf("All nodes are connected.\n");
    } else {
        printf("Not all nodes are connected.\n");
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent checking for connectivity: %f seconds\n", time_spent);
    memUsage = (float)(usage.ru_maxrss / (1024.0f * 1024.0f)); // Convert to MB
    printf("Memory usage: %d MB\n\n", (int)memUsage);

    freeGraph(graph);

    return 0;
}
