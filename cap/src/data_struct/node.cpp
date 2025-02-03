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
}

void Node::addEdgeSorted(uint32_t destID, uint32_t time)
{
    auto it = lower_bound(edges.begin(), edges.end(), destID, [](const Edge &edge, uint32_t destID) {
        return edge.destID < destID;
    });

    edges.insert(it, Edge(destID, time));
}