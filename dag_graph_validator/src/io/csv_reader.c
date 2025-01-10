#include "csv_reader.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CHUNCK_SIZE 64

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

LineType readFileLine(FILE *file){
    LineType line;
    char chunck[CHUNCK_SIZE];
    char* token;

    fgets(chunck, CHUNCK_SIZE, file);

    token = strtok(chunck, ",");
    line.id = token;
    token = strtok(NULL, ",");
    line.destId = token;
    token = strtok(NULL, ",");
    line.distance = strtoul(token, NULL, 10);
    return line;
}
