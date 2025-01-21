/*!
    \file graph.hpp
    \brief The header file for the Graph class
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <cstdint>
#include <cstring> 
#include <iostream>
#include "node.hpp"

#define HASH_MAP_SIZE 30000000 // Maximal number of nodes in the graph

/*!
    \class Graph
    \brief Represents a graph with nodes, edges, and a hash map for quick access.
    \remark The graph isn't oriented, so adding an edge from A to B will also add an edge from B to A.
*/
class Graph {
    private:
        uint32_t numNodes;
        long long numEdges;
        Node* head;
        Node* nodeMap[HASH_MAP_SIZE];

    public:
        /*!
            \brief Constructor for the Graph class
            Initializes the graph with no nodes and an empty hash map.
        */
        Graph();

        /*!
            \brief Destructor for the Graph class
            Frees all dynamically allocated nodes and their edges.
        */
        ~Graph();

        /*!
            \brief Get the number of nodes in the graph
            \return The number of nodes in the graph
        */
        uint32_t getNumNodes() const;

        /*!
            \brief Get the edges of the graph
            \return The number of edges in the graph
        */
        long long getNumEdges() const;

        /*!
            \brief Get the head node of the graph
            \return Pointer to the head node of the graph
        */
        Node* getHead() const;

        /*!
            \brief Get a node from the hash map
            \param index The index of the node in the hash map
            \return Pointer to the node at the index, or nullptr if not found
        */
        Node* getNodeMap(uint32_t index) const;

        /*!
            \brief Set the number of nodes in the graph
            \param numNodes The new number of nodes
        */
        void setNumNodes(uint32_t numNodes);

        /*!
            \brief Set the head node of the graph
            \param head Pointer to the new head node
        */
        void setHead(Node* head);

        /*!
            \brief Set a node in the hash map
            \param index The index of the node in the hash map
            \param node Pointer to the node to set
        */
        void setNodeMap(uint32_t index, Node* node);

        /*!
            \brief Add an edge to the graph (in fact 2 edges, one for each node)
            \param from The starting node ID
            \param to The ending node ID
            \param distance The distance between the nodes
            \return True if the edge was successfully added, false otherwise
        */
        bool addEdge(uint32_t from, uint32_t to, uint32_t distance);

        /*!
            \brief Deleted copy constructor to prevent shallow copies
        */
        Graph(const Graph&) = delete;

        /*!
            \brief Deleted copy assignment operator to prevent shallow copies
        */
        Graph& operator=(const Graph&) = delete;

        /*!
            \brief Move constructor
            Transfers ownership of graph resources.
        */
        Graph(Graph&& other) noexcept;

        /*!
            \brief Move assignment operator
            Transfers ownership of graph resources.
        */
        Graph& operator=(Graph&& other) noexcept;
};
