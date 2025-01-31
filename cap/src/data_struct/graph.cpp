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
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        current->~Node();
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
    edge0->next = fromNode->head;
    fromNode->addEdgeSorted(edge0); // Keep the edges sorted by time
    this->numEdges++;

    fromNode->next = this->head;

    // New edge for the other node
    Edge *edge1 = new Edge(fromNode, distance);
    edge1->next = toNode->head;
    toNode->addEdgeSorted(edge1); // Keep the edges sorted by time
    this->numEdges++;

    toNode->next = fromNode;
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
            Node *nextNode = current->next;
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

    auto compare = [&](uint32_t a, uint32_t b)
    { return distances[a] > distances[b]; };
    priority_queue<uint32_t, vector<uint32_t>, decltype(compare)> pq(compare);

    pq.push(from);

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
        {
            continue;
        }

        Edge *edge = currentNode->head;
        while (edge != nullptr)
        {
            uint32_t neighborId = edge->self->id;
            uint32_t newDist = distances[currentId] + edge->time;

            if (newDist < distances[neighborId])
            {
                distances[neighborId] = newDist;
                previous[neighborId] = currentId;
                pq.push(neighborId);
            }

            edge = edge->next;
        }
    }

    vector<uint32_t> path;
    for (int at = to; at != -1; at = previous[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

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
    if (landmarkDistances.size() != landmarks.size())
    {
        throw runtime_error("Mismatch: landmarkDistances does not match the number of landmarks.");
    }

    if (from >= numNodes || to >= numNodes || from < 1 || to < 1)
    {
        throw out_of_range("Invalid node indices: from = " + std::to_string(from) + ", to = " + std::to_string(to));
    }

    vector<uint32_t> distances(numNodes, UINT32_MAX);
    vector<int> previous(numNodes, -1);
    distances[from] = 0;

    auto compare = [&](uint32_t a, uint32_t b)
    {
        if (a >= distances.size() || b >= distances.size())
        {
            cerr << "Error: comparator accessing out-of-bounds index." << endl;
            throw std::out_of_range("Comparator out of bounds");
        }
        return distances[a] > distances[b];
    };
    priority_queue<uint32_t, vector<uint32_t>, decltype(compare)> pq(compare);

    pq.push(from);

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

        Edge *edge = currentNode->head;

        while (edge != nullptr)
        {
            uint32_t neighborId = edge->self->id;
            uint32_t newDist = distances[currentId] + edge->time;

            if (newDist < distances[neighborId])
            {
                distances[neighborId] = newDist;
                previous[neighborId] = currentId;
                pq.push(neighborId);
            }
            edge = edge->next;
        }
    }

    vector<uint32_t> path;
    for (int at = to; at != -1; at = previous[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return (path[0] == from) ? path : vector<uint32_t>();
}

pair<uint32_t, uint32_t> Graph::farthestPathWeightedBFS(uint32_t start) {
    vector<uint32_t> distances(numNodes, 0);
    vector<bool> visited(numNodes, false);
    distances[start] = 0;

    priority_queue<pair<uint32_t, uint32_t>> pq;
    pq.push({1, start});

    uint32_t farthestNode = start;
    uint32_t maxDistance = 0;

    while (!pq.empty()) {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (visited[currentNode]) {
            continue;
        }
        visited[currentNode] = true;

        if (currentDistance > maxDistance) {
            maxDistance = currentDistance;
            farthestNode = currentNode;
        }

        Node* node = nodeMap[currentNode];
        if (!node) {
            continue;
        }

        Edge* edge = node->head;
        while (edge) {
            uint32_t neighbor = edge->self->id;
            uint32_t weight = edge->time;
            uint32_t newDistance = distances[currentNode] + weight;

            if (newDistance > distances[neighbor]) {
                distances[neighbor] = newDistance;
                pq.push({newDistance, neighbor});
            }

            edge = edge->next;
        }
    }

    return {farthestNode, maxDistance};
}
