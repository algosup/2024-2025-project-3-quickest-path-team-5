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
private:
    uint32_t numNodes;
    long long numEdges;
    Node *head;
    Node *nodeMap[HASH_MAP_SIZE];
    vector<uint32_t> landmarks;                  // List of landmark nodes
    vector<vector<uint32_t>> landmarkDistances;  // Distances between landmark nodes

public:
    /*!
        \brief Constructor for the Graph class
        Initializes the graph with no nodes and an empty hash map.
    */
    Graph();

    /*!
        \brief Destructor for the Graph class
        Frees all dynamically allocated nodes and their edges.
    */
    ~Graph();

    /*!
        \brief Get the number of nodes in the graph
        \return The number of nodes in the graph
    */
    uint32_t getNumNodes() const;

    /*!
        \brief Get the edges of the graph
        \return The number of edges in the graph
    */
    long long getNumEdges() const;

    /*!
        \brief Get the head node of the graph
        \return Pointer to the head node of the graph
    */
    Node *getHead() const;

    /*!
        \brief Get a node from the hash map
        \param index The index of the node in the hash map
        \return Pointer to the node at the index, or nullptr if not found
    */
    Node *getNodeMap(uint32_t index) const;

    /*!
        \brief Set the number of nodes in the graph
        \param numNodes The new number of nodes
    */
    void setNumNodes(uint32_t numNodes);

    /*!
        \brief Set the head node of the graph
        \param head Pointer to the new head node
    */
    void setHead(Node *head);

    /*!
        \brief Set a node in the hash map
        \param index The index of the node in the hash map
        \param node Pointer to the node to set
    */
    void setNodeMap(uint32_t index, Node *node);

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
        \brief Move assignment operator
        Transfers ownership of graph resources.
    */
    Graph &operator=(Graph &&other) noexcept;

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
        \brief A* algorithm to find the shortest path between two nodes
        \param from The source node
        \param to The destination node
        \return A vector containing the shortest distance to each node
    */
    vector<uint32_t> aStarLandmark(uint32_t from, uint32_t to);

    /*!
        \brief Find the farthest pair of nodes in the graph
        \return A pair of node IDs representing the farthest pair of nodes
    */
    pair<uint32_t, uint32_t> farthestPath();

    /*!
        \brief Select a number of landmark nodes to use in the A* algorithm
        \param numLandmarks The number of landmarks to select
    */
    void selectLandmarks(size_t numLandmarks);
};
