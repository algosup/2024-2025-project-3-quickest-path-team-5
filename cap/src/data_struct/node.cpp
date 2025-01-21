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
        Edge *nextEdge = current->getNext();
        delete current;
        current = nextEdge;
    }
}

uint32_t Node::getId() const
{
    return this->id;
}

Edge *Node::getHead() const
{
    return this->head;
}

Node *Node::getNext() const
{
    return this->next;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

void Node::setHead(Edge *head)
{
    this->head = head;
}

void Node::incrementNumEdges()
{
    this->numEdges++;
}

void Node::decrementNumEdges()
{
    this->numEdges--;
}

uint32_t Node::getNumEdges() const
{
    return this->numEdges;
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
            Edge *nextEdge = current->getNext();
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