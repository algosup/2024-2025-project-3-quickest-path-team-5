/*!
    \file node.cpp
    \brief The file for the Node class implementation
    \authors CHARLES Rémy, CARON Maxime
*/

#include <iostream>
#include "node.hpp"

using namespace std;

Node::Node(uint32_t id)
{
    this->id = id;
    this->head = nullptr;
    this->numEdges = 0;
    this->next = nullptr;
}

Node::~Node()
{
    Edge *current = head;
    while (current != nullptr)
    {
        Edge *nextEdge = current->next;
        current->~Edge();
        current = nextEdge;
    }
    this->head = nullptr;
    this->next = nullptr;
}

void Node::addEdgeSorted(Edge *edge)
{
    this->numEdges++;
    if (this->head == nullptr)
    {
        edge->next = head;
        head = edge;
        return;
    }

    Edge *current = head;
    while (current->next != nullptr && current->next->time < edge->time)
    {
        current = current->next;
    }

    edge->next = current->next;
    current->next = edge;
}

Node::Node(Node &&other) noexcept
    : id(other.id), head(other.head), next(other.next)
{
    other.head = nullptr;
    other.next = nullptr;
}

Node &Node::operator=(Node &&other) noexcept
{
    if (this != &other)
    {
        // Free current edges
        Edge *current = head;
        while (current)
        {
            Edge *nextEdge = current->next;
            delete current;
            current = nextEdge;
        }

        // Transfer ownership
        id = other.id;
        head = other.head;
        next = other.next;

        other.head = nullptr;
        other.next = nullptr;
    }
    return *this;
}