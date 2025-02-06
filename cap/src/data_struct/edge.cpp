/*!
    \file edge.cpp
    \brief The file for the Edge class implementation
    \authors CHARLES Rémy, CARON Maxime
*/
#include <iostream>
#include "edge.hpp"

using namespace std;

Edge::Edge(uint32_t destID, uint32_t time)
{
    this->destID = destID;
    this->time = time;
}