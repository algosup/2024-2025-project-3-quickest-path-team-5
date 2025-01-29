/*!
    \file graph.cpp
    \brief The file for the Graph class implementation
    \authors CHARLES Rémy, CARON Maxime
*/

#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>

#include "graph.hpp"

#define MIN_NODE 1

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
    fromNode->addEdgeSorted(edge0); // Keep the edges sorted by time
    this->numEdges++;

    fromNode->setNext(this->head);

    // New edge for the other node
    Edge *edge1 = new Edge(fromNode, distance);
    edge1->setNext(toNode->getHead());
    toNode->addEdgeSorted(edge1); // Keep the edges sorted by time
    this->numEdges++;

    toNode->setNext(fromNode);
    this->head = toNode;

    return true;
}
bool Graph::addLandmark(uint32_t landmark)
{
    if (landmark >= HASH_MAP_SIZE)
    {
        return false;
    }
    landmarks.push_back(landmark);
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
        cout << "No path found from " << from << " to " << to << endl;
        path.clear();
    }
    return path;
}

void Graph::computeLandmarkDistances()
{
    landmarkDistances.clear(); // Clear any previously computed distances
    for (uint32_t landmark : landmarks)
    {
        if (landmark >= numNodes)
        {
            throw std::out_of_range("Landmark index out of bounds");
        }
        if (!nodeMap[landmark])
        {
            throw std::runtime_error("Landmark does not exist in the graph.");
        }

        vector<uint32_t> distances = dijkstra(landmark, this->numNodes - 1);
        landmarkDistances.push_back(distances);
    }
}

vector<uint32_t> Graph::aStarLandmark(uint32_t from, uint32_t to)
{
    // Validate landmarkDistances dimensions
    if (landmarkDistances.size() != landmarks.size())
    {
        throw runtime_error("Mismatch: landmarkDistances does not match the number of landmarks.");
    }

    // Validate input indices
    if (from >= numNodes || to >= numNodes || from < 1 || to < 1)
    {
        throw out_of_range("Invalid node indices: from = " + std::to_string(from) + ", to = " + std::to_string(to));
    }

    // Initialize distances and previous nodes
    vector<uint32_t> distances(numNodes, UINT32_MAX);
    vector<int> previous(numNodes, -1);
    distances[from] = 0;

    // Priority queue with heuristic
    auto compare = [&](uint32_t a, uint32_t b) {
        uint32_t h_a = 0, h_b = 0;
        for (size_t i = 0; i < landmarks.size(); ++i) {
            h_a = (h_a > (uint32_t)abs((int)landmarkDistances[i][a] - (int)landmarkDistances[i][to])) ? h_a : (uint32_t)abs((int)landmarkDistances[i][a] - (int)landmarkDistances[i][to]);
            h_b = (h_b > (uint32_t)abs((int)landmarkDistances[i][b] - (int)landmarkDistances[i][to])) ? h_b : (uint32_t)abs((int)landmarkDistances[i][b] - (int)landmarkDistances[i][to]);
        }
        return distances[a] + h_a > distances[b] + h_b;
    };
    priority_queue<uint32_t, vector<uint32_t>, decltype(compare)> pq(compare);

    pq.push(from);

    // Process the graph
    while (!pq.empty())
    {
        uint32_t currentId = pq.top();
        pq.pop();

        if (currentId == to)
        {
            break;
        }

        Node *currentNode = nodeMap[currentId];
        if (!currentNode)
            continue;

        Edge *edge = currentNode->getHead();
        while (edge != nullptr)
        {
            uint32_t neighborId = edge->getSelf()->getId();
            uint32_t newDist = distances[currentId] + edge->getTime();


            if (newDist < distances[neighborId])
            {
                distances[neighborId] = newDist;
                previous[neighborId] = currentId;
                pq.push(neighborId);
            }


            edge = edge->getNext();
        }

    }

    // Construct the path
    vector<uint32_t> path;
    for (int at = to; at != -1; at = previous[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return (path[0] == from) ? path : vector<uint32_t>();
}

pair<uint32_t, uint32_t> Graph::farthestPath()
{
    vector<bool> visited(numNodes, false);
    uint32_t farthestNode = 0, maxDistance = 0;

    for (uint32_t start = 0; start < numNodes; ++start)
    {
        if (visited[start])
            continue;

        // Run Dijkstra from this component
        vector<uint32_t> distances(numNodes, UINT32_MAX);
        distances[start] = 0;

        priority_queue<pair<uint32_t, uint32_t>, vector<pair<uint32_t, uint32_t>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            auto [dist, current] = pq.top();
            pq.pop();

            if (dist > maxDistance)
            {
                maxDistance = dist;
                farthestNode = current;
            }

            if (visited[current])
                continue;
            visited[current] = true;

            Node *currentNode = nodeMap[current];
            if (!currentNode)
                continue;

            Edge *edge = currentNode->getHead();
            while (edge)
            {
                uint32_t neighbor = edge->getSelf()->getId();
                uint32_t newDist = distances[current] + edge->getTime();

                if (newDist < distances[neighbor])
                {
                    distances[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }

                edge = edge->getNext();
            }
        }
    }

    return {1, farthestNode};
}

void Graph::selectLandmarks(size_t numLandmarks) {
    landmarks.clear();
    if (numNodes == 0 || numLandmarks == 0) return;

    for (size_t i = 0; i < numLandmarks; ++i) {
        uint32_t farthestNode = MIN_NODE;
        uint32_t maxDistance = 0;

        for (uint32_t node = MIN_NODE; node < numNodes; ++node) {
            uint32_t minDistToLandmarks = this->numNodes- 1;

            for (uint32_t landmark : landmarks) {
                vector<uint32_t> distances = dijkstra(landmark, this->numNodes - 1);
                minDistToLandmarks = (minDistToLandmarks > distances[node]) ? distances[node] : minDistToLandmarks;
            }

            if (minDistToLandmarks > maxDistance) {
                maxDistance = minDistToLandmarks;
                farthestNode = node;
            }
        }
        cout << "Selected landmark: " << farthestNode << endl;
        landmarks.push_back(farthestNode);
    }
}
