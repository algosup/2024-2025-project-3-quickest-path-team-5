#include "mermaid_writter.h"

bool writeMermaidNode(const char *filename, char* point1, char* point2, unsigned long distance)
{
    if (filename == NULL)
    {
        return false;
    }
    FILE *file = fopen(filename, "ab");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "%s--%lu-->%s\n", point1, distance, point2);
    fclose(file);
    return true;
}
