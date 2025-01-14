/*!
    \file csv_reader.c
    \brief The header file for the CSV reader
    \authors CHARLES Rémy, CARON Maxime
*/

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

bool readFileLine(FILE *file , LineType *line){
    char chunck[CHUNCK_SIZE];
    char* token;

    fgets(chunck, CHUNCK_SIZE, file);
    if (feof(file))
    {
        return false;
    }

    token = strtok(chunck, ",");
    line->id = token;
    token = strtok(NULL, ",");
    line->destId = token;
    token = strtok(NULL, ",");
    line->distance = strtoul(token, NULL, 10);
    return true;
}
