/*!
    \file csv_reader.hpp
    \brief CSV reader functions definition
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <stdio.h>
#include <iostream>
#include <string.h>

#include "graph.hpp"

/*!
    \brief Check if a file exists
    \param filename The name of the file to check
    \return True if the file exists, false otherwise
*/
bool checkFileExists(const char *filename);

/*!
    \brief Read a CSV file and fill the graph with the data
    \param graph the graph to add the edge to
    \param file the file to read
*/
void loadDataset(Graph* graph, const char* filename);