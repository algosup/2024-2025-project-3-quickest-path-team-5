/*!
    \file edge.cpp
    \brief The file for the Edge class implementation
    \authors CHARLES Rémy, CARON Maxime
*/
#include <iostream>
#include "edge.hpp"

using namespace std;

Edge::Edge(Node *self, uint32_t time)
{
    this->self = self;
    this->time = time;
    this->next = nullptr;
}

Edge::~Edge()
{
    cout << "Deleting edge " << this << endl;
    next = nullptr;
}

Node *Edge::getSelf() const
{
    return this->self;
}

uint32_t Edge::getTime() const
{
    return this->time;
}

Edge *Edge::getNext() const
{
    return this->next;
}

void Edge::setNext(Edge *next)
{
    this->next = next;
}

Edge::Edge(Edge &&other) noexcept
    : self(other.self), time(other.time), next(other.next)
{
    other.self = nullptr;
    other.next = nullptr;
}

Edge &Edge::operator=(Edge &&other) noexcept
{
    if (this != &other)
    {
        Edge *current = next;
        while (current)
        {
            Edge *nextEdge = current->getNext();
            delete current;
            current = nextEdge;
        }

        self = other.self;
        time = other.time;
        next = other.next;
        other.self = nullptr;
        other.next = nullptr;
    }
    return *this;
}