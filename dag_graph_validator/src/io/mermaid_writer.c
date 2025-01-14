#include "mermaid_writter.h"

bool writeMermaidNode(const char *filename, const char *point1, const char *point2, uint32_t distance) {
    if (filename == NULL || point1 == NULL || point2 == NULL) {
        return false;
    }

    FILE *file = fopen(filename, "a"); // Use "a" for appending to the file
    if (file == NULL) {
        return false;
    }

    fprintf(file, "%s -- %u --> %s\n", point1, distance, point2); // Corrected format specifier for uint32_t
    fclose(file);

    return true;
}

