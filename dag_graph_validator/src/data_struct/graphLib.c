/*!
    \file graphLib.c
    \brief Graph library
    \authors CHARLES Rémy, CARON Maxime
*/

#include "graphLib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void graphCreate(GraphType *self) {
    self->num_nodes = 0;
    self->nodes = NULL;
    self->node_lookup = NULL;
    self->is_directed = false;
    self->is_weighted = false;
    self->max_degree = 0;
}

void graphDestroy(GraphType *self) {
    for (size_t i = 0; i < self->num_nodes; ++i) {
        free(self->nodes[i]->parents);
        free(self->nodes[i]->childs);
        free(self->nodes[i]);
    }
    free(self->nodes);
    free(self->node_lookup);
    self->num_nodes = 0;
    self->nodes = NULL;
    self->node_lookup = NULL;
}

bool graphEmpty(const GraphType *self) {
    return self->num_nodes == 0;
}

size_t graphSize(const GraphType *self) {
    return self->num_nodes;
}

bool graphContains(const GraphType *self, uint32_t id) {
    for (size_t i = 0; i < self->num_nodes; ++i) {
        if (self->nodes[i]->id == id) {
            return true;
        }
    }
    return false;
}

bool linkExist(GraphType *self, uint32_t id1, uint32_t id2) {
    for (size_t i = 0; i < self->num_nodes; ++i) {
        if (self->nodes[i]->id == id1) {
            for (size_t j = 0; j < self->nodes[i]->num_links; ++j) {
                if (self->nodes[i]->childs[j].node->id == id2) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool graphCreateNode(GraphType *self, uint32_t id) {
    if (graphContains(self, id)) {
        return false;
    }

    NodeType *new_node = (NodeType *)malloc(sizeof(NodeType));
    if (!new_node) {
        return false;
    }

    new_node->id = id;
    new_node->num_links = 0;
    new_node->parents = NULL;
    new_node->childs = NULL;
    new_node->visited = false;
    new_node->discovery_time = 0;
    new_node->finish_time = 0;

    self->nodes = (NodeType **)realloc(self->nodes, (self->num_nodes + 1) * sizeof(NodeType *));
    self->node_lookup = (NodeType **)realloc(self->node_lookup, (self->num_nodes + 1) * sizeof(NodeType *));

    if (!self->nodes || !self->node_lookup) {
        free(new_node);
        return false;
    }

    self->nodes[self->num_nodes] = new_node;
    self->node_lookup[self->num_nodes] = new_node;
    self->num_nodes++;

    return true;
}

bool createLink(GraphType *self, uint32_t parentId, uint32_t id, uint32_t distance) {
    NodeType *parent = NULL;
    NodeType *child = NULL;

    for (size_t i = 0; i < self->num_nodes; ++i) {
        if (self->nodes[i]->id == parentId) {
            parent = self->nodes[i];
        }
        if (self->nodes[i]->id == id) {
            child = self->nodes[i];
        }
    }

    if (!parent || !child) {
        return false;
    }

    parent->childs = (LinkType *)realloc(parent->childs, (parent->num_links + 1) * sizeof(LinkType));
    if (!parent->childs) {
        return false;
    }

    parent->childs[parent->num_links].node = child;
    parent->childs[parent->num_links].distance = distance;
    parent->num_links++;

    if (!self->is_directed) {
        child->parents = (LinkType *)realloc(child->parents, (child->num_links + 1) * sizeof(LinkType));
        if (!child->parents) {
            return false;
        }

        child->parents[child->num_links].node = parent;
        child->parents[child->num_links].distance = distance;
        child->num_links++;
    }

    return true;
}

bool graphRemoveNode(GraphType *self, uint32_t id) {
    for (size_t i = 0; i < self->num_nodes; ++i) {
        if (self->nodes[i]->id == id) {
            free(self->nodes[i]->parents);
            free(self->nodes[i]->childs);
            free(self->nodes[i]);

            for (size_t j = i; j < self->num_nodes - 1; ++j) {
                self->nodes[j] = self->nodes[j + 1];
            }

            self->num_nodes--;
            self->nodes = (NodeType **)realloc(self->nodes, self->num_nodes * sizeof(NodeType *));
            self->node_lookup = (NodeType **)realloc(self->node_lookup, self->num_nodes * sizeof(NodeType *));

            return true;
        }
    }
    return false;
}

bool removeLink(GraphType *self, uint32_t parentId, uint32_t id) {
    NodeType *parent = NULL;

    for (size_t i = 0; i < self->num_nodes; ++i) {
        if (self->nodes[i]->id == parentId) {
            parent = self->nodes[i];
            break;
        }
    }

    if (!parent) {
        return false;
    }

    for (size_t i = 0; i < parent->num_links; ++i) {
        if (parent->childs[i].node->id == id) {
            for (size_t j = i; j < parent->num_links - 1; ++j) {
                parent->childs[j] = parent->childs[j + 1];
            }
            parent->num_links--;
            parent->childs = (LinkType *)realloc(parent->childs, parent->num_links * sizeof(LinkType));
            return true;
        }
    }

    return false;
}

bool dfsCheckLoop(NodeType *node, bool *visited, bool *recStack, size_t max_nodes) {
    if (node == NULL || node->id >= max_nodes) {
        return false;
    }

    if (!visited[node->id]) {
        visited[node->id] = true;
        recStack[node->id] = true;

        for (size_t i = 0; i < node->num_links; ++i) {
            NodeType *child = node->childs[i].node;
            if (child == NULL || child->id >= max_nodes) {
                continue;
            }
            if (!visited[child->id] && dfsCheckLoop(child, visited, recStack, max_nodes)) {
                return true;
            } else if (recStack[child->id]) {
                return true;
            }
        }
    }
    recStack[node->id] = false;
    return false;
}

bool hasLoop(GraphType *graph) {
    if (graph == NULL || graph->nodes == NULL || graph->num_nodes == 0) {
        return false;
    }

    bool *visited = calloc(graph->num_nodes, sizeof(bool));
    bool *recStack = calloc(graph->num_nodes, sizeof(bool));
    if (visited == NULL || recStack == NULL) {
        free(visited);
        free(recStack);
        return false;
    }

    for (size_t i = 0; i < graph->num_nodes; ++i) {
        if (graph->nodes[i] == NULL) {
            continue;
        }
        if (!visited[i] && dfsCheckLoop(graph->nodes[i], visited, recStack, graph->num_nodes)) {
            free(visited);
            free(recStack);
            return true;
        }
    }

    free(visited);
    free(recStack);
    return false;
}

void dfsReachable(NodeType *node, bool *visited, size_t max_nodes) {
    if (node == NULL || node->id >= max_nodes) {
        return;
    }

    visited[node->id] = true;
    for (size_t i = 0; i < node->num_links; ++i) {
        NodeType *child = node->childs[i].node;
        if (child != NULL && child->id < max_nodes && !visited[child->id]) {
            dfsReachable(child, visited, max_nodes);
        }
    }
}

bool areAllNodesReachable(GraphType *graph) {
    if (graph == NULL || graph->nodes == NULL || graph->num_nodes == 0) {
        return false;
    }

    bool *visited = calloc(graph->num_nodes, sizeof(bool));
    if (visited == NULL) {
        return false;
    }

    for (size_t i = 0; i < graph->num_nodes; ++i) {
        if (graph->nodes[i] != NULL) {
            dfsReachable(graph->nodes[i], visited, graph->num_nodes);
            break;
        }
    }

    for (size_t i = 0; i < graph->num_nodes; ++i) {
        if (graph->nodes[i] != NULL && !visited[graph->nodes[i]->id]) {
            printf("Node %u is not reachable\n", graph->nodes[i]->id); // Debugging log
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}


