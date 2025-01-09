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
typedef struct Link
{
    struct Node *node;
    unsigned long distance;
} LinkType;

/*!
    \typedef Node
    \brief A struct representing a node and its links in a graph
*/
typedef struct Node
{
    unsigned long id;
    size_t num_links;
    LinkType *links;
} NodeType;

/*!
    \typedef Graph
    \brief A struct representing a graph
*/
typedef struct Graph
{
    size_t num_nodes;
    NodeType **nodes;
} GraphType;

#ifdef __cplusplus
extern "C"
{
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
        \brief Tell if a link exists between two nodes
        \param self The graph to check
        \param id1 The id of the first node
        \param id2 The id of the second node
        \return True if the link exists, false otherwise
    */
    bool linkExist(GraphType *self, unsigned long id1, unsigned long id2);

    /*!
        \brief Create a node in the graph
        \param self The graph to create the node in
        \param id The id of the node to create
        \return True if the node was created, false otherwise
    */
    bool graphCreateNode(GraphType *self, unsigned long id);

    /*!
        \brief Create a link between two nodes in the graph
        \param self The graph to create the link in
        \param parentId The id of the parent node
        \param id The id of the node to link to
        \param distance The distance between the two nodes
        \return True if the link was created, false otherwise
    */
    bool createLink(GraphType *self, unsigned long parentId, unsigned long id, unsigned long distance);

    /*!
        \brief Remove a node from the graph
        \param self The graph to remove the node from
        \param id The id of the node to remove
        \return True if the node was removed, false otherwise
    */
    bool graphRemoveNode(GraphType *self, unsigned long id);

    /*!
        \brief Remove a link between two nodes in the graph
        \param self The graph to remove the link from
        \param parentId The id of the parent node
        \param id The id of the node to unlink
        \return True if the link was removed, false otherwise
    */
    bool removeLink(GraphType *self, unsigned long parentId, unsigned long id);

#ifdef __cplusplus
}
#endif
