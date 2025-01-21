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
private:
    Node *self;
    uint32_t time;
    Edge *next;

public:
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
        \brief Get the node the edge is connected to
        \return The node the edge is connected to
    */
    Node *getSelf() const;

    /*!
        \brief Get the time it takes to travel the edge
        \return The time it takes to travel the edge
    */
    uint32_t getTime() const;

    /*!
        \brief Get the next edge
        \return The next edge
    */
    Edge *getNext() const;

    /*!
        \brief Set the next edge
        \param next The next edge
    */
    void setNext(Edge *next);

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
