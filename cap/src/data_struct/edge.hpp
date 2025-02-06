/*!
    \file edge.hpp
    \brief The header file for the Edge class
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once
#include <cstdint>

class Node;

class Edge {
public:
    uint32_t destID;
    uint32_t time;

    Edge(uint32_t destID, uint32_t time);
    ~Edge() = default;
};
