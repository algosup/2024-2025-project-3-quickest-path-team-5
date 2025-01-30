#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "csv_reader.h"
#include "graphviz_exporter.h"
#include "graphLib.h"

#define FILE_PATH "../../data/USA-roads.csv"
#define EXPRT_FILE_PATH "../../data/USA-roads.dot"

int main(void) {
    char* defaultFilePath = FILE_PATH;
    char* defaultExportFile = EXPRT_FILE_PATH;
    bool isExtracted = false;

    printf("Enter the path to the dataset file (default: %s): ", defaultFilePath);
    char input[1024];
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = 0; // Remove the newline character
        defaultFilePath = input;
    }

    if(!checkFileExists(FILE_PATH)) {
        fprintf(stderr, "File not found: %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }


    printf("Do you want to export the graph? (y/n): ");
    fgets(input, sizeof(input), stdin);
    if (input[0] == 'y' || input[0] == 'Y') {
        isExtracted = true;
    }

    if (isExtracted) {
        printf("Enter the path to the exporting file (default: %s): ", defaultExportFile);
        fgets(input, sizeof(input), stdin);
        if (input[0] != '\n') {
            input[strcspn(input, "\n")] = 0; // Remove the newline character
            defaultExportFile = input;
        }
    }

    

    struct rusage usage;
    graph_t* graph = createGraph();
    clock_t begin = clock();    
    readDataset(graph, FILE_PATH);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent reading the dataset: %f seconds\n", time_spent);

    begin = clock();    
    if (isDAG(graph)) {
        printf("The graph is a Directed Acyclic Graph (DAG).\n");
    } else {
        printf("The graph is not a DAG.\n");
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent checking for cycles: %f seconds\n", time_spent);

    begin = clock();    
    if (areAllNodesAccessible(graph)) {
        printf("All nodes are connected.\n");
    } else {
        printf("Not all nodes are connected.\n");
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent checking for connectivity: %f seconds\n", time_spent);

    if (isExtracted) {
        begin = clock();    
        if (exportGraphvizFile(defaultExportFile, graph)) {
            printf("File exported successfully.\n");
        } else {
            fprintf(stderr, "Failed to write the Mermaid file.\n");
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time spent exporting the graph: %f seconds\n", time_spent);
    }

    freeGraph(graph);

    return 0;
}
