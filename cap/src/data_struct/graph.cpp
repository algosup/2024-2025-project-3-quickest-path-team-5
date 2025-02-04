/*!
    \file graph.cpp
    \brief The file for the Graph class implementation
    \authors CHARLES Rémy, CARON Maxime
*/

#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>

#include <thread>
#include <mutex>
#include <future>

#include "graph.hpp"

using namespace std;

Graph::Graph() : numNodes(0), numEdges(0)
{
    minNode = UINT32_MAX;
    maxNode = 0;
    memset(nodeMap, 0, sizeof(nodeMap)); // Initialize the hash map to nullptr
}

bool Graph::addEdge(uint32_t from, uint32_t to, uint32_t distance)
{
    if (from >= HASH_MAP_SIZE || to >= HASH_MAP_SIZE)
    {
        cerr << "Error: Node index out of bounds. from = " << from << ", to = " << to << endl;
        return false;
    }

    Node *fromNode = this->nodeMap[from];
    if (fromNode == nullptr)
    {
        fromNode = new Node(from);
        this->nodeMap[from] = fromNode;

        if (from < minNode)
        {
            minNode = from;
        }
        if (from > maxNode)
        {
            maxNode = from;
        }
        this->numNodes++;
    }

    Node *toNode = this->nodeMap[to];
    if (toNode == nullptr)
    {
        toNode = new Node(to);
        this->nodeMap[to] = toNode;

        if (to < minNode)
        {
            minNode = to;
        }
        if (to > maxNode)
        {
            maxNode = to;
        }
        this->numNodes++;
    }

    fromNode->addEdgeSorted(toNode->id, distance);

    toNode->addEdgeSorted(fromNode->id, distance);

    this->numEdges += 2;

    return true;
}

bool Graph::addLandmark(uint32_t landmark)
{
    if (landmark >= HASH_MAP_SIZE)
    {
        return false;
    }
    landmarks.push_back(landmark);
    numLandmarks++;
    return true;
}

Graph::Graph(Graph &&other) noexcept
    : numNodes(other.numNodes)
{
    memcpy(nodeMap, other.nodeMap, sizeof(nodeMap));
    other.numNodes = 0;
    memset(other.nodeMap, 0, sizeof(other.nodeMap));
}

vector<uint32_t> Graph::nodeComputeDijkstra(uint32_t from, uint32_t to)
{
    constexpr uint32_t INF = numeric_limits<uint32_t>::max();
    vector<uint32_t> dist(HASH_MAP_SIZE, INF);
    dist[from] = 0;

    using Pair = pair<uint32_t, uint32_t>; // (distance, node)
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(0, from);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (u == to)
            break; // Early exit if target is reached
        if (d > dist[u])
            continue;

        Node *u_node = nodeMap[u];
        for (const Edge &edge : u_node->edges)
        {
            uint32_t v = edge.destID;
            uint32_t new_dist = d + edge.time;

            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    return dist;
}

vector<uint32_t> Graph::dijkstra(uint32_t from, uint32_t to)
{
    constexpr uint32_t INF = numeric_limits<uint32_t>::max();
    vector<uint32_t> dist(HASH_MAP_SIZE, INF);
    vector<int> previous(numNodes, -1); // To reconstruct the shortest path
    dist[from] = 0;

    using Pair = pair<uint32_t, uint32_t>; // (distance, node)
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(0, from);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (u == to)
            break; // Early exit if target is reached
        if (d > dist[u])
            continue;

        Node *u_node = nodeMap[u];
        for (const Edge &edge : u_node->edges)
        {
            uint32_t v = edge.destID;
            uint32_t new_dist = d + edge.time;

            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                previous[v] = u;
                pq.emplace(new_dist, v);
            }
        }
    }
    if (to == UINT32_MAX)
    {
        return dist;
    }
    vector<uint32_t> path;
    for (int at = to; at != -1; at = previous[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    return path;
}

void Graph::computeLandmarkDistances()
{
    landmarkDistances.resize(numLandmarks);
    for (size_t i = 0; i < numLandmarks; ++i)
    {
        uint32_t landmark = landmarks[i];
        landmarkDistances[i] = nodeComputeDijkstra(landmark, 0); // dummy target
    }
}

uint32_t Graph::heuristic(uint32_t u, const vector<uint32_t> &landmarkToDists) const
{
    uint32_t h = 0;
    for (size_t i = 0; i < numLandmarks; ++i)
    {
        int32_t diff = static_cast<int32_t>(landmarkDistances[i][u]) - landmarkToDists[i];
        h = max(h, static_cast<uint32_t>(abs(diff)));
    }
    return h;
}

vector<uint32_t> Graph::aStarLandmark(uint32_t from, uint32_t to)
{
    if (from == to)
        return {0};

    constexpr uint32_t INF = numeric_limits<uint32_t>::max();
    vector<uint32_t> dist(HASH_MAP_SIZE, INF);
    vector<int> previous(numNodes, -1);
    dist[from] = 0;

    vector<uint32_t> landmarkToDists(numLandmarks);
    for (size_t i = 0; i < numLandmarks; ++i)
    {
        landmarkToDists[i] = landmarkDistances[i][to];
    }

    using Pair = pair<uint32_t, uint32_t>;
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(heuristic(from, landmarkToDists), from);

    while (!pq.empty())
    {
        auto [f, u] = pq.top();
        pq.pop();

        if (u == to)
            break; // Early exit

        uint32_t g_u = dist[u];
        if (f > g_u + heuristic(u, landmarkToDists))
            continue;

        Node *u_node = nodeMap[u];
        for (const Edge &edge : u_node->edges)
        {
            uint32_t v = edge.destID;
            uint32_t new_g = g_u + edge.time;

            if (new_g < dist[v])
            {
                dist[v] = new_g;
                previous[v] = u;
                uint32_t h_v = heuristic(v, landmarkToDists);
                pq.emplace(new_g + h_v, v);
            }
        }
    }

    if (to == UINT32_MAX)
    {
        return dist;
    }
    vector<uint32_t> path;
    for (int at = to; at != -1; at = previous[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    return path;
}

vector<uint32_t> Graph::multiSourceDijkstra(const vector<uint32_t>& sources) {
    vector<uint32_t> dist(HASH_MAP_SIZE, UINT32_MAX);
    priority_queue<pair<uint32_t, uint32_t>, vector<pair<uint32_t, uint32_t>>, greater<>> pq;

    for (uint32_t src : sources) {
        if (src >= HASH_MAP_SIZE || !nodeMap[src]) continue;
        dist[src] = 0;
        pq.emplace(0, src);
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        Node* u_node = nodeMap[u];
        for (const Edge& edge : u_node->edges) {
            uint32_t v = edge.destID;
            if (v >= HASH_MAP_SIZE || !nodeMap[v]) continue;

            uint32_t new_dist = d + edge.time;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    return dist;
}

void Graph::selectLandmarks(uint32_t count) {
    landmarks.clear();
    numLandmarks = 0;

    if (count == 0 || numNodes == 0) return;

    uint32_t first = UINT32_MAX;
    for (uint32_t i = 0; i < HASH_MAP_SIZE; ++i) {
        if (nodeMap[i]) {
            first = i;
            break;
        }
    }
    if (first == UINT32_MAX) return;

    addLandmark(first);

    for (uint32_t i = 1; i < count; ++i) {
        vector<uint32_t> min_dists = multiSourceDijkstra(landmarks);
        
        uint32_t max_dist = 0;
        uint32_t farthest = UINT32_MAX;
        
        for (uint32_t node = 0; node < HASH_MAP_SIZE; ++node) {
            if (!nodeMap[node] || find(landmarks.begin(), landmarks.end(), node) != landmarks.end()) 
                continue;

            if (min_dists[node] > max_dist && min_dists[node] != UINT32_MAX) {
                max_dist = min_dists[node];
                farthest = node;
            }
        }

        if (farthest == UINT32_MAX) break;
        
        addLandmark(farthest);
    }

    computeLandmarkDistances();
}