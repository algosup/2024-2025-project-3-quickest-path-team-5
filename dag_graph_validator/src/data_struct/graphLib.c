/*!
    \file graphLib.c
    \brief Graph library
    \authors CHARLES Rémy, CARON Maxime
*/

#include "graphLib.h"

#define UNVISITED 0
#define VISITING  1
#define VISITED   2

graph_t* createGraph(void) {
    graph_t* graph = (graph_t*)malloc(sizeof(graph_t));
    if (!graph) {
        return NULL;
    }
    graph->numNodes = 0;
    graph->head = NULL;
    return graph;
}

uint32_t hash(uint32_t id) {
    return id % HASH_MAP_SIZE;
}

bool addEdge(graph_t* graph, uint32_t from, uint32_t to, uint32_t distance) {
    uint32_t fromHash = hash(from);
    uint32_t toHash = hash(to);

    node_t* fromNode = graph->nodeMap[fromHash];
    node_t* toNode = graph->nodeMap[toHash];

    while (fromNode != NULL && fromNode->id != from) {
        fromNode = fromNode->next;
    }
    while (toNode != NULL && toNode->id != to) {
        toNode = toNode->next;
    }

    if (fromNode == NULL) {
        fromNode = (node_t*)malloc(sizeof(node_t));
        if (!fromNode) {
            return false;
        }
        fromNode->id = from;
        fromNode->head = NULL;
        fromNode->next = graph->nodeMap[fromHash];
        graph->nodeMap[fromHash] = fromNode;

        fromNode->next = graph->head;
        graph->head = fromNode;
        graph->numNodes++;
    }

    if (toNode == NULL) {
        toNode = (node_t*)malloc(sizeof(node_t));
        if (!toNode) {
            return false;
        }
        toNode->id = to;
        toNode->head = NULL;
        toNode->next = graph->nodeMap[toHash];
        graph->nodeMap[toHash] = toNode;

        toNode->next = graph->head;
        graph->head = toNode;
        graph->numNodes++;
    }

    edge_t* edge = (edge_t*)malloc(sizeof(edge_t));
    if (!edge) {
        return false;
    }
    edge->self = toNode;
    edge->distance = distance;
    edge->next = fromNode->head;
    fromNode->head = edge;

    return true;
}

bool dfsCheckDAG(node_t* node, uint8_t* visited) {
    if (visited[node->id] == VISITING) {
        return false;
    }
    if (visited[node->id] == VISITED) {
        return true;
    }

    visited[node->id] = VISITING;

    edge_t* edge = node->head;
    while (edge) {
        if (!dfsCheckDAG(edge->self, visited)) {
            return false;
        }
        edge = edge->next;
    }

    visited[node->id] = VISITED;
    return true;
}

bool isDAG(graph_t* graph) {
    if (!graph || !graph->head) {
        return true;
    }

    uint8_t* visited = (uint8_t*)calloc(graph->numNodes, sizeof(uint8_t));
    if (!visited) {
        perror("Failed to allocate memory for visited array");
        exit(EXIT_FAILURE);
    }

    node_t* current = graph->head;
    while (current) {
        if (visited[current->id] == UNVISITED) {
            if (!dfsCheckDAG(current, visited)) {
                free(visited);
                return false;
            }
        }
        current = current->next;
    }

    free(visited);
    return true;
}

bool dfs(node_t* node, bool* visited, uint32_t* idToIndex) {
    if (visited[idToIndex[node->id]]) {
        return false;
    }

    visited[idToIndex[node->id]] = true;

    edge_t* edge = node->head;
    while (edge) {
        dfs(edge->self, visited, idToIndex);
        edge = edge->next;
    }

    return true;
}

bool areAllNodesAccessible(graph_t* graph) {
    if (!graph || !graph->head) {
        return false;
    }

    bool* visited = (bool*)calloc(graph->numNodes, sizeof(bool));
    if (!visited) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node_t* current = graph->head;
    uint32_t index = 0;
    uint32_t* idToIndex = (uint32_t*)malloc(graph->numNodes * sizeof(uint32_t));
    if (!idToIndex) {
        fprintf(stderr, "Memory allocation failed\n");
        free(visited);
        exit(EXIT_FAILURE);
    }

    while (current) {
        idToIndex[current->id] = index++;
        current = current->next;
    }

    dfs(graph->head, visited, idToIndex);

    bool allAccessible = true;
    for (uint32_t i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            allAccessible = false;
            break;
        }
    }

    free(visited);
    free(idToIndex);

    return allAccessible;
}
void printGraph(graph_t* graph){
    node_t* current = graph->head;
    while (current) {
        printf("Node %u: ", current->id);
        edge_t* edge = current->head;
        while (edge) {
            printf("\t->%u", edge->self->id);
            edge = edge->next;
        }
        printf("\n");
        current = current->next;
    }
}

void freeGraph(graph_t* graph) {
    node_t* current = graph->head;
    while (current) {
        edge_t* edge = current->head;
        while (edge) {
            edge_t* next = edge->next;
            free(edge);
            edge = next;
        }
        node_t* next = current->next;
        free(current);
        current = next;
    }
    free(graph);
}
