/*!
    \file csv_reader.h
    \brief The header file for the CSV reader
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "graphLib.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
    \brief Check if a file exists
    \param filename The name of the file to check
    \return True if the file exists, false otherwise
*/
bool checkFileExists(const char *filename);

/*!
    \brief Read a CSV file and return its contents as Graph
    \param filename The name of the file to read
    \return The contents of the file
*/
GraphType readFormatCSV(const char *filename);

#ifdef __cplusplus
}
#endif