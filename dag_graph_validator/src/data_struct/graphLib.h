/*!
    \file graphLib.h
    \brief Graph library
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


#define HASH_MAP_SIZE 30000000

typedef struct Node {
    uint32_t id;
    struct Node* next;
    struct Edge* head;
} node_t;

typedef struct Edge {
    node_t* self;
    uint32_t distance;
    struct Edge* next;
} edge_t;

typedef struct Graph {
    uint32_t numNodes;
    node_t* head;
    node_t* nodeMap[HASH_MAP_SIZE]; // Hash map for quick node lookup
} graph_t;


#ifdef __cplusplus
extern "C"
{
#endif

/*!
    \brief Hash function for the graph
    \param id The id to hash
    \return The hashed id
*/
uint32_t hash(uint32_t id);

/*!
    \brief Create a graph
    \return A pointer to the graph
*/
graph_t* createGraph(void);

/*!
    \brief Add an edge to the graph
    \param graph The graph to add the edge to
    \param from The starting node
    \param to The ending node
    \param distance The distance between the nodes
    \return True if the edge was added, false otherwise
*/
bool addEdge(graph_t* graph, uint32_t from, uint32_t to, uint32_t distance);

/*!
    \brief Detect a cycle in the graph
    \param node The node to check
    \param visited The visited nodes
    \return True if a cycle is detected, false otherwise
*/
bool dfsCheckDAG(node_t* node, uint8_t* visited);

/*!
    \brief Check if the graph is a Directed Acyclic Graph (DAG)
    \param graph The graph to check
    \return True if the graph is a DAG, false otherwise
*/
bool isDAG(graph_t* graph);

/*!
    \brief Depth-first search
    \param node The node to start the search from
    \param visited The visited nodes
    \param idToIndex The mapping of node id to index
    \return True if the search was successful, false otherwise
*/
bool dfs(node_t* node, bool* visited, uint32_t* idToIndex);

/*!
    \brief Check if all nodes are connected
    \param graph The graph to check
    \return True if all nodes are connected, false otherwise
*/
bool areAllNodesAccessible(graph_t* graph);

/*!
    \brief Print the graph
    \param graph The graph to print
*/
void printGraph(graph_t* graph);

/*!
    \brief Free the graph
    \param graph The graph to free
*/
void freeGraph(graph_t* graph);

#ifdef __cplusplus
}
#endif
