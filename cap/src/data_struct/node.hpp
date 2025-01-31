/*!
    \file node.hpp
    \brief The header file for the Node class
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <cstdint>
#include "edge.hpp"

class Edge; // Forward declaration of the Edge class

/*!
    \class Node
    \brief Represents a node in a graph, which may have a linked list of edges and a link to the next node.
*/
class Node {
    public:
        uint32_t id;
        Edge* head;
        uint32_t numEdges;
        Node* next;

        /*!
            \brief Constructor for the Node class
            \param id The unique identifier for the node
        */
        explicit Node(uint32_t id);

        /*!
            \brief Destructor for the Node class
            Frees all associated edges.
        */
        ~Node();
        /*!
            \brief Add an edge to the node's edge list and keep it sorted by time
            \param edge Pointer to the edge to add
        */
        void addEdgeSorted(Edge* edge);

        /*!
            \brief Deleted copy constructor to prevent unintended shallow copies
        */
        Node(const Node&) = delete;

        /*!
            \brief Deleted copy assignment operator to prevent unintended shallow copies
        */
        Node& operator=(const Node&) = delete;

        /*!
            \brief Move constructor
        */
        Node(Node&& other) noexcept;

        /*!
            \brief Move assignment operator
        */
        Node& operator=(Node&& other) noexcept;
};
