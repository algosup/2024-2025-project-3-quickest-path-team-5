#include "csv_reader.h"

bool checkFileExists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

GraphType readFormatCSV(const char *filename){
    GraphType graph;
    
    FILE *file = fopen(filename, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    }
    return graph;
}