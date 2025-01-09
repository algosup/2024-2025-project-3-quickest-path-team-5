/*!
    \file graphLib.h
    \brief Graph library
    \authors CHARLES Rémy, CARON Maxime
*/


#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*!
    \typedef Link
    \brief A struct representing a link between two nodes
*/
typedef struct Link {
    struct Node *node;
    unsigned long distance;
} LinkType;

/*!
    \typedef Node
    \brief A struct representing a node and its links in a graph
*/
typedef struct Node {
    unsigned long id;
    size_t num_links;
    LinkType *links;
} NodeType;

/*!
    \typedef Graph
    \brief A struct representing a graph
*/
typedef struct Graph {
    size_t num_nodes;
    NodeType *node;
} GraphType;

#ifdef __cplusplus
extern "C" {
#endif

/*!
    \brief Create a graph
    \param self The graph to create
*/
void graphCreate(GraphType *self);

/*!
    \brief Destroy a graph
    \param self The graph to destroy
*/
void graphDestroy(GraphType *self);

/*!
    \brief Tell if a graph is empty
    \param self The graph to check
    \return True if the graph is empty, false otherwise
*/
bool graphEmpty(const GraphType *self);

/*!
    \brief Get the number of nodes in the graph
    \param self The graph to check
    \return The number of nodes in the graph
*/
size_t graphSize(const GraphType *self);

/*!
    \brief Tell if a graph contains a node
    \param self The graph to check
    \param id The id of the node to look for
    \return True if the graph contains the node, false otherwise
*/
bool graphContains(const GraphType *self, unsigned long id);

/*!
    \brief Insert a node in the graph
    \param self The graph to insert the node in
    \param parentId The id of the parent node
    \param id The id of the node to insert
    \param distance The distance between the parent and the node
    \return True if the node was inserted, false otherwise
*/
bool graphInsert(GraphType *self, unsigned long parentId, unsigned long id, unsigned long distance);

/*!
    \brief Remove a node from the graph
    \param self The graph to remove the node from
    \param id The id of the node to remove
    \return True if the node was removed, false otherwise
*/
bool graphRemove(GraphType *self, unsigned long id);

#ifdef __cplusplus
}
#endif
