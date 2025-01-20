/*!
    \file csv_reader.c
    \brief The header file for the CSV reader
    \authors CHARLES Rémy, CARON Maxime
*/

#include "csv_reader.h"

bool checkFileExists(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file)
    {
        fclose(file);
        return true;
    }
    return false;
}


void readDataset(graph_t* graph, const char* filename) {
    printf("Reading dataset from file: %s\n", filename);

    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char buffer[1024]; // Buffer for reading lines
    uint32_t pointA, pointB, distance;
    size_t lineCount = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "%u, %u, %u", &pointA, &pointB, &distance) != 3) {
            fprintf(stderr, "Malformed line at %zu: %s\n", lineCount + 1, buffer);
            continue;
        }

        if (!addEdge(graph, pointA, pointB, distance)) {
            fprintf(stderr, "Error: Memory allocation failed at line %zu\n", lineCount + 1);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        lineCount++;
    }

    fclose(file);
    printf("Dataset read successfully. Total lines processed: %zu\n", lineCount);
}



