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
    private:
        uint32_t id;
        Edge* head;
        Node* next;

    public:
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
            \brief Get the ID of the node
            \return The ID of the node
        */
        uint32_t getId() const;

        /*!
            \brief Get the head of the edge list
            \return Pointer to the head of the edge list
        */
        Edge* getHead() const;

        /*!
            \brief Get the next node in the linked list
            \return Pointer to the next node
        */
        Node* getNext() const;

        /*!
            \brief Set the next node in the linked list
            \param next Pointer to the next node
        */
        void setNext(Node* next);

        /*!
            \brief Set the head of the edge list
            \param head Pointer to the new head of the edge list
        */
        void setHead(Edge* head);

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
