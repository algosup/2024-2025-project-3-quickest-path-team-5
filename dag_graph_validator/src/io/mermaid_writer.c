#include "mermaid_writter.h"

bool writeMermaidFile(const char *filename, graph_t* graph) {
    if (!graph || !graph->head) {
        return false;
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return false;
    }

    node_t* current = graph->head;
    while (current) {
        edge_t* edge = current->head;
        while (edge) {
            fprintf(file, "%u-->%u: %u\n", current->id, edge->self->id, edge->distance);
            edge = edge->next;
        }
        current = current->next;
    }


    fclose(file);

    return true;
}

