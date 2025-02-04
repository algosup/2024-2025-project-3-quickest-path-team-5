/*!
    \file node.hpp
    \brief The header file for the Node class
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once
#include <cstdint>
#include <vector>
#include "edge.hpp"

class Node {
public:
    uint32_t id;
    std::vector<Edge> edges;

    explicit Node(uint32_t id);
    void addEdgeSorted(uint32_t destID, uint32_t time);
};
