/*!
    \file mermaid_writter.h
    \brief This file contains the declaration of the MermaidWritter class.
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*!
    \brief Write a mermaid node in a file
    \param filename The name of the file to write
    \param point1 The first point
    \param point2 The second point
    \param distance The distance between the two points
    \return True if the file was written, false otherwise
*/
bool writeMermaidNode(const char *filename, char* point1, char* point2, unsigned long distance);

#ifdef __cplusplus
}
#endif
