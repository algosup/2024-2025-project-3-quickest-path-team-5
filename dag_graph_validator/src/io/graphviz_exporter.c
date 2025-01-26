#include "graphviz_exporter.h"

bool exportGraphvizFile(const char *filename, graph_t* graph) {
    if (!graph || !graph->head) {
        return false;
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return false;
    }

    // Write the header
    fprintf(file, "strict graph G {\n");
    node_t* current = graph->head;
    while (current) {
        edge_t* edge = current->head;
        while (edge) {
            fprintf(file, "%u -- %u [len=%u, label=%u]; \n", current->id, edge->self->id, edge->distance, edge->distance);
            edge = edge->next;
        }
        current = current->next;
    }
    fprintf(file, "}\n");


    fclose(file);

    return true;
}

