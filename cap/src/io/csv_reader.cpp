/*!
    \file csv_reader.cpp
    \brief CSV reader functions implementation
    \authors CHARLES Rémy, CARON Maxime
*/

#include "csv_reader.hpp"

using namespace std;

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

void loadDataset(Graph* graph, const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }
    cout << "loading dataset from file: " << filename << endl;
    char line[256];
    uint32_t pointA, pointB, distance;
        size_t lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%u, %u, %u", &pointA, &pointB, &distance) != 3) {
            cerr << "Error: malformed line at " << lineCount + 1 << ": " << line << endl;
            continue;
        }

        if (!graph->addEdge(pointA, pointB, distance)) {
            cerr << "Error: Memory allocation failed at line " << lineCount + 1 << endl;
            fclose(file);
            exit(EXIT_FAILURE);
        }

        lineCount++;
    }

    cout << "Dataset load successfully. Total lines processed: " << lineCount << endl;
    fclose(file);
}