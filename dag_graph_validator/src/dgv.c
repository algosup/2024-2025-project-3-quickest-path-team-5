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

int main(void)
{
    printf("Verify that file %s exists\n", FILE_PATH);

    // Start measuring execution time
    clock_t start_time = clock();

    // Check if the file exists
    if (checkFileExists(FILE_PATH))
    {
        printf("File exists\n");
    }
    else
    {
        printf("File does not exist\n");
        return 1;
    }

    FILE *file = fopen(FILE_PATH, "r");
    if (!file)
    {
        printf("Error: could not open file %s\n", FILE_PATH);
        return 1;
    }

    // Initialize the graph
    GraphType graph;
    graphCreate(&graph);

    LineType *line = malloc(sizeof(LineType));
    while (readFileLine(file, line)) // Assumes `readFileLine` returns true on success
    {
        if (line->id == NULL || line->destId == NULL)
        {
            continue; // Skip invalid lines
        }

        // Convert IDs to integers
        uint32_t id = strtoul(line->id, NULL, 10);
        uint32_t destId = strtoul(line->destId, NULL, 10);

        // Add nodes if they do not exist
        if (!graphContains(&graph, id))
        {
            if (!graphCreateNode(&graph, id))
            {
                printf("Error: Failed to create node with ID %u\n", id);
                fclose(file);
                graphDestroy(&graph);
                return 1;
            }
        }

        if (!graphContains(&graph, destId))
        {
            if (!graphCreateNode(&graph, destId))
            {
                printf("Error: Failed to create node with ID %u\n", destId);
                fclose(file);
                graphDestroy(&graph);
                return 1;
            }
        }

        // Create a link between the nodes
        if (!createLink(&graph, id, destId, line->distance))
        {
            printf("Error: Failed to create link between %u and %u\n", id, destId);
            fclose(file);
            graphDestroy(&graph);
            return 1;
        }

        // reset line
        line->id = NULL;
        line->destId = NULL;
        line->distance = 0;
    }
    free(line);
    fclose(file);

    // Check if the graph is empty
    if (graphEmpty(&graph))
    {
        printf("Graph is empty\n");
        graphDestroy(&graph);
        return 1;
    }

    bool has_loop = hasLoop(&graph);
    bool all_reachable = areAllNodesReachable(&graph);

    // Display results
    printf("Graph has %sloop\n", has_loop ? "a " : "no ");
    printf("All nodes are %sreachable\n", all_reachable ? "" : "not ");

    // End measuring execution time
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Summary
    printf("\n=== Summary ===\n");
    printf("Graph Analysis Results:\n");
    printf("- Loop: %s\n", has_loop ? "Yes" : "No");
    printf("- All Nodes Reachable: %s\n", all_reachable ? "Yes" : "No");
    printf("Execution Time: %.2f seconds\n", time_taken);

    // Destroy the graph to free resources
    graphDestroy(&graph);

    return 0;
}
