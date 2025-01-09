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

GraphType readFormatCSV(const char *filename)
{
    GraphType graph;

    FILE *file = fopen(filename, "r");
    if (file)
    {
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            unsigned long id, destId, distance;
            sscanf(line, "%lu,%lu,%lu", &id, &destId, &distance);
            if (id > graph.num_nodes)
            {
                graph.num_nodes = id;
            }
            if (destId > graph.num_nodes)
            {
                graph.num_nodes = destId;
            }
        }
        fclose(file);
    }
    return graph;
}