/*!
    \file edge.hpp
    \brief The header file for the Edge class
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <cstdint> // For uint32_t
#include "node.hpp"

class Node;// Forward declaration of the Node class

/*!
    \class Edge
    \brief Represents an edge in a graph, connecting to a node and having a weight/time.
*/
class Edge
{
public:
    Node *self;
    uint32_t time;
    Edge *next;

    /*!
        \brief Constructor for the Edge class
        \param self The node the edge is connected to
        \param time The time it takes to travel the edge
    */
    Edge(Node *self, uint32_t time);

    /*!
        \brief Destructor for the Edge class
    */
    ~Edge();

    /*!
        \brief Deleted copy constructor to prevent unintended shallow copies
    */
    Edge(const Edge &) = delete;

    /*!
        \brief Deleted copy assignment operator to prevent unintended shallow copies
    */
    Edge &operator=(const Edge &) = delete;

    /*!
        \brief Move constructor
    */
    Edge(Edge &&other) noexcept;

    /*!
        \brief Move assignment operator
    */
    Edge &operator=(Edge &&other) noexcept;
};
