/*!
    \file mermaid_writter.h
    \brief This file contains the declaration of the MermaidWritter class.
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "graphLib.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!
    \brief exportGraphvizFile Writes a graph to a file in the Graphviz format
    \param filename The name of the file to write
    \param graph The graph to write
    \return True if all went well, false otherwise
*/
bool exportGraphvizFile(const char *filename, graph_t* graph);

#ifdef __cplusplus
}
#endif
