/*!
    \file node.cpp
    \brief The file for the Node class implementation
    \authors CHARLES Rémy, CARON Maxime
*/

#include <iostream>
#include <algorithm>
#include "node.hpp"

using namespace std;

Node::Node(uint32_t id)
{
    this->id = id;
}

// Define a functor for comparing an Edge with a destination ID.
struct EdgeComparator {
    bool operator()(const Edge &edge, uint32_t destID) const {
        return edge.destID < destID;
    }
};

void Node::addEdgeSorted(uint32_t destID, uint32_t time)
{
    // Use std::lower_bound with the functor.
    auto it = std::lower_bound(edges.begin(), edges.end(), destID, EdgeComparator());
    
    // Insert the new Edge at the found position.
    edges.insert(it, Edge(destID, time));
}