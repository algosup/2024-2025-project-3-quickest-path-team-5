/*!
    \file graph.cpp
    \brief The file for the Graph class implementation
    \authors CHARLES Rémy, CARON Maxime
*/

#include <queue>
#include <climits>
#include <iostream>
#include <cstdint>

#include "graph.hpp"

using namespace std;

Graph::Graph() : numNodes(0), numEdges(0), head(nullptr)
{
    memset(nodeMap, 0, sizeof(nodeMap)); // Initialize the hash map to nullptr
}

Graph::~Graph()
{
    Node *current = head;
    while (current)
    {
        Node *nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

uint32_t Graph::getNumNodes() const
{
    return this->numNodes;
}

long long Graph::getNumEdges() const
{
    return this->numEdges;
}

Node *Graph::getHead() const
{
    return this->head;
}

Node *Graph::getNodeMap(uint32_t index) const
{
    return this->nodeMap[index];
}

void Graph::setNumNodes(uint32_t numNodes)
{
    this->numNodes = numNodes;
}

void Graph::setHead(Node *head)
{
    this->head = head;
}

void Graph::setNodeMap(uint32_t index, Node *node)
{
    this->nodeMap[index] = node;
}

bool Graph::addEdge(uint32_t from, uint32_t to, uint32_t distance)
{
    if (from >= HASH_MAP_SIZE || to >= HASH_MAP_SIZE)
    {
        return false;
    }

    Node *fromNode = this->nodeMap[from];
    Node *toNode = this->nodeMap[to];

    if (fromNode == nullptr)
    {
        fromNode = new Node(from);
        this->nodeMap[from] = fromNode;
        this->numNodes++;
    }

    if (toNode == nullptr)
    {
        toNode = new Node(to);
        this->nodeMap[to] = toNode;
        this->numNodes++;
    }

    Edge *edge0 = new Edge(toNode, distance);
    edge0->setNext(fromNode->getHead());
    fromNode->setHead(edge0);
    fromNode->incrementNumEdges();
    this->numEdges++;

    fromNode->setNext(this->head);

    // New edge for the other node
    Edge *edge1 = new Edge(fromNode, distance);
    edge1->setNext(toNode->getHead());
    toNode->setHead(edge1);
    toNode->incrementNumEdges();
    this->numEdges++;

    toNode->setNext(fromNode);
    this->head = toNode;

    return true;
}

Graph::Graph(Graph &&other) noexcept
    : numNodes(other.numNodes), head(other.head)
{
    memcpy(nodeMap, other.nodeMap, sizeof(nodeMap));
    other.head = nullptr;
    other.numNodes = 0;
    memset(other.nodeMap, 0, sizeof(other.nodeMap));
}

Graph &Graph::operator=(Graph &&other) noexcept
{
    if (this != &other)
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->getNext();
            delete current;
            current = nextNode;
        }

        numNodes = other.numNodes;
        head = other.head;
        memcpy(nodeMap, other.nodeMap, sizeof(nodeMap));

        other.head = nullptr;
        other.numNodes = 0;
        memset(other.nodeMap, 0, sizeof(other.nodeMap));
    }
    return *this;
}

vector<uint32_t> Graph::dijkstra(uint32_t from, uint32_t to)
{
    // Initialize distances with infinity and previous nodes with -1
    vector<uint32_t> distances(numNodes, UINT32_MAX);
    vector<int> previous(numNodes, -1);
    distances[from] = 0;

    // Priority queue to pick the node with the minimum distance
    auto compare = [&](uint32_t a, uint32_t b)
    { return distances[a] > distances[b]; };
    priority_queue<uint32_t, vector<uint32_t>, decltype(compare)> pq(compare);

    // Push the source node to the priority queue
    pq.push(from);

    // Process the graph
    while (!pq.empty())
    {
        uint32_t currentId = pq.top();
        pq.pop();

        // If we reach the destination, stop the algorithm
        if (currentId == to)
        {
            break;
        }

        Node *currentNode = nodeMap[currentId]; // Get the current node
        if (!currentNode)
        {
            continue; // Skip if node is null
        }

        // Explore each edge from the current node
        Edge *edge = currentNode->getHead();
        while (edge != nullptr)
        {
            uint32_t neighborId = edge->getSelf()->getId();
            uint32_t newDist = distances[currentId] + edge->getTime();

            // If a shorter path is found, update the distance and previous node
            if (newDist < distances[neighborId])
            {
                distances[neighborId] = newDist;
                previous[neighborId] = currentId;
                pq.push(neighborId);
            }

            edge = edge->getNext();
        }
    }

    // Construct the shortest path from 'from' to 'to' using the previous array
    vector<uint32_t> path;
    for (int at = to; at != -1; at = previous[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // If the path doesn't start with the source node, no path exists
    if (path[0] != from)
    {
        path.clear();
    }

    return path;
}
