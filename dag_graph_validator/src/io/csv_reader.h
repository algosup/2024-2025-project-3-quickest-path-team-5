/*!
    \file csv_reader.h
    \brief The header file for the CSV reader
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct line
{
    char* id;
    char* destId;
    unsigned long distance;
} LineType;

#ifdef __cplusplus
extern "C"
{
#endif

/*!
    \brief Check if a file exists
    \param filename The name of the file to check
    \return True if the file exists, false otherwise
*/
bool checkFileExists(const char *filename);

/*!
    \brief Read a CSV file and return a list of lineType struct
    \param file the file to read
    \return A lineType struct
*/
LineType readFileLine(FILE *file);

#ifdef __cplusplus
}
#endif
