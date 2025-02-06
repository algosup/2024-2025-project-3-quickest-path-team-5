/*!
    \file graph.hpp
    \brief The header file for the Graph class
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <cstdint>
#include <cstring>
#include <vector>
#include <chrono>

#include "node.hpp"
#include "edge.hpp"

#define HASH_MAP_SIZE 30000000 // Maximal number of nodes in the graph

using namespace std;
/*!
    \class Graph
    \brief Represents a graph with nodes, edges, and a hash map for quick access.
    \remark The graph isn't oriented, so adding an edge from A to B will also add an edge from B to A.
*/
class Graph
{
public:
    uint32_t numNodes;
    long long numEdges;
    uint32_t minNode;
    uint32_t maxNode;
    vector<Node> nodes;
    Node *nodeMap[HASH_MAP_SIZE];
    uint32_t numLandmarks;                      // Number of landmark nodes
    vector<uint32_t> landmarks;                 // List of landmark nodes
    vector<vector<uint32_t>> landmarkDistances; // Distances between landmark nodes

    /*!
        \brief Constructor for the Graph class
        Initializes the graph with no nodes and an empty hash map.
    */
    Graph();

    /*!
        \brief Add an edge to the graph (in fact 2 edges, one for each node)
        \param from The starting node ID
        \param to The ending node ID
        \param distance The distance between the nodes
        \return True if the edge was successfully added, false otherwise
    */
    bool addEdge(uint32_t from, uint32_t to, uint32_t distance);

    /*!
        \brief Add a landmark node to the graph
        \param landmark The landmark node ID
        \return True if the landmark was successfully added, false otherwise
    */
    bool addLandmark(uint32_t landmark);

    /*!
        \brief Deleted copy constructor to prevent shallow copies
    */
    Graph(const Graph &) = delete;

    /*!
        \brief Deleted copy assignment operator to prevent shallow copies
    */
    Graph &operator=(const Graph &) = delete;

    /*!
        \brief Move constructor
        Transfers ownership of graph resources.
    */
    Graph(Graph &&other) noexcept;

    /*!
        \brief Dijkstra's algorithm to find the shortest path between two nodes specificly used to compute nodes for landmarks
        \param from The source node
        \param to The destination node
        \return A vector containing the shortest distance to each node
    */
    vector<uint32_t> nodeComputeDijkstra(uint32_t from, uint32_t to);

    /*!
        \brief Dijkstra's algorithm to find the shortest path between two nodes
        \param from The source node
        \param to The destination node
        \return A vector containing the shortest distance to each node
     */
    vector<uint32_t> dijkstra(uint32_t from, uint32_t to);

    /*!
        \brief Graph precomputation to compute the distances between landmark nodes
    */
    void computeLandmarkDistances();

    /*!
        \brief Heuristic function for A* algorithm
        \param u The current node
        \param landmarkToDists The distances to the landmark nodes
        \return The heuristic value
    */
    uint32_t heuristic(uint32_t u, const vector<uint32_t> &landmarkToDists) const;

    /*!
        \brief A* algorithm to find the shortest path between two nodes
        \param from The source node
        \param to The destination node
        \return A vector containing the shortest distance to each node
    */
    vector<uint32_t> aStarLandmark(uint32_t from, uint32_t to);

    /*!
        \brief Select landmarks for heuristic computation
        \param count The number of landmarks to select
    */
    void selectLandmarks(uint32_t count);

    /*!
        \brief Multi-source Dijkstra's algorithm to find the shortest path between multiple nodes
        \param sources The source nodes
        \return A vector containing the shortest distance to each node
    */
    vector<uint32_t> multiSourceDijkstra(const vector<uint32_t>& sources);

};
