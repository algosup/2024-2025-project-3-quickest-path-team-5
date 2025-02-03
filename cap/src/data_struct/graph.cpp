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

vector<uint32_t> Graph::dijkstra(uint32_t from, uint32_t to)
{
    constexpr uint32_t INF = numeric_limits<uint32_t>::max();

    // Validate node indices
    if (from >= numNodes || to >= numNodes)
    {
        cerr << "Error: Invalid 'from' or 'to' node index (from = " << from << ", to = " << to << ")" << endl;
        return {};
    }

    vector<uint32_t> dist(numNodes, INF); // Use numNodes instead of HASH_MAP_SIZE
    vector<int64_t> previous(numNodes, -1); // Store previous node for path reconstruction
    dist[from] = 0;

    using Pair = pair<uint32_t, uint32_t>;
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(0, from);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        // Critical safety check
        if (!nodeMap[u]) {
            cerr << "Warning: Invalid node " << u << " in priority queue\n";
            continue;
        }

        if (u == to && d == dist[to]) break;
        if (d > dist[u]) continue;

        Node *u_node = nodeMap[u];
        for (const Edge &edge : u_node->edges)
        {
            uint32_t v = edge.destID;

            // Validate 'v' index
            if (v >= numNodes)
            {
                cerr << "Error: Edge points to invalid node ID (v = " << v << ")." << endl;
                continue;
            }

            uint32_t new_dist = d + edge.time;

            // Relaxation step
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                previous[v] = u;
                pq.emplace(new_dist, v);
            }
        }
    }

    // Reconstruct the shortest path
    vector<uint32_t> path;
    for (int at = to; at != -1; at = previous[at])
    {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());

    // Validate that the path starts at 'from'
    if (path.empty() || path[0] != from)
    {
        cerr << "No path found from " << from << " to " << to << "." << endl;
        return {};
    }

    return path;
}


void Graph::computeLandmarkDistances()
{
    landmarkDistances.clear();

    mutex mutex;

    auto processLandmark = [&](uint32_t landmark)
    {
        vector<uint32_t> distances(numNodes, UINT32_MAX);
        distances = dijkstra(landmark, numNodes-1);

        lock_guard<std::mutex> lock(mutex);
        landmarkDistances.push_back(distances);
    };

    vector<future<void>> futures;
    for (uint32_t i = 0; i < numLandmarks; ++i)
    {
        futures.push_back(async(launch::async, processLandmark, landmarks[i]));
    }

    for (auto &future : futures)
    {
        future.get();
    }
}

uint32_t Graph::heuristic(uint32_t u, uint32_t to, const std::vector<uint32_t>& landmarkToDists) const {
    uint32_t h = 0;
    for (size_t i = 0; i < numLandmarks; ++i) {
        int32_t diff = static_cast<int32_t>(landmarkDistances[i][u]) - landmarkToDists[i];
        h = std::max(h, static_cast<uint32_t>(std::abs(diff)));
    }
    return h;
}

std::vector<uint32_t> Graph::aStarLandmark(uint32_t from, uint32_t to) {
    if (from == to) return {0};

    constexpr uint32_t INF = std::numeric_limits<uint32_t>::max();
    std::vector<uint32_t> dist(HASH_MAP_SIZE, INF);
    dist[from] = 0;

    // Precompute landmark distances to 'to'
    std::vector<uint32_t> landmarkToDists(numLandmarks);
    for (size_t i = 0; i < numLandmarks; ++i) {
        landmarkToDists[i] = landmarkDistances[i][to];
    }

    using Pair = std::pair<uint32_t, uint32_t>; // (f = g + h, node)
    std::priority_queue<Pair, std::vector<Pair>, std::greater<>> pq;
    pq.emplace(heuristic(from, to, landmarkToDists), from);

    while (!pq.empty()) {
        auto [f, u] = pq.top();
        pq.pop();

        if (u == to) break; // Early exit

        uint32_t g_u = dist[u];
        if (f > g_u + heuristic(u, to, landmarkToDists)) continue;

        Node* u_node = nodeMap[u];
        for (const Edge& edge : u_node->edges) {
            uint32_t v = edge.destID;
            uint32_t new_g = g_u + edge.time;

            if (new_g < dist[v]) {
                dist[v] = new_g;
                uint32_t h_v = heuristic(v, to, landmarkToDists);
                pq.emplace(new_g + h_v, v);
            }
        }
    }

    return dist;
}