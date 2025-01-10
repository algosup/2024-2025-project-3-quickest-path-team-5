#include <stdio.h>
#include <stdlib.h>

#include "csv_reader.h"
#include "mermaid_writter.h"
#include "treeLib.h"

#define FILE_PATH "../../data/USA-roads.csv"
#define MERMAID_FILE "../../data/USA-roads.mmd"

int main(void)
{
    printf("Verify that file %s exists\n", FILE_PATH);

    if (checkFileExists(FILE_PATH))
    {
        printf("File exists\n");
    }
    else
    {
        printf("File does not exist\n");
        return 1;
    }

    printf("Verify that file %s exists\n", MERMAID_FILE);

    if (checkFileExists(MERMAID_FILE))
    {
        printf("File exists\nContent will be overwritten\n");
    }
    else
    {
        printf("File does not exist\nFile will be created\n");
    }

    FILE *file = fopen(FILE_PATH, "rb");
    TreeType *tree = malloc(sizeof(TreeType));
    treeCreate(tree);

    do {
        LineType newLine = readFileLine(file);
        writeMermaidNode(MERMAID_FILE, newLine.id, newLine.destId, newLine.distance);
        treeInsert(tree, strtoul(newLine.id, NULL, 10));
        treeInsert(tree, strtoul(newLine.destId, NULL, 10));
    } while (!feof(file));

    printf("Graph nodes: %zu\n", treeSize(tree));
    printf("Graph height: %zu\n", treeHeight(tree));

    treeDestroy(tree);
    fclose(file);

    return 0;
}
