/*!
    \file graph.cpp
    \brief The file for the Graph class implementation
    \authors CHARLES Rémy, CARON Maxime
*/

#include "graph.hpp"

using namespace std;

Graph::Graph() : numNodes(0), head(nullptr) {
    std::memset(nodeMap, 0, sizeof(nodeMap)); // Initialize the hash map to nullptr
}

Graph::~Graph() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}


uint32_t Graph::getNumNodes() const
{
    return this->numNodes;
}

Node* Graph::getHead() const
{
    return this->head;
}

Node* Graph::getNodeMap(uint32_t index) const
{
    return this->nodeMap[index];
}

void Graph::setNumNodes(uint32_t numNodes)
{
    this->numNodes = numNodes;
}

void Graph::setHead(Node* head)
{
    this->head = head;
}

void Graph::setNodeMap(uint32_t index, Node* node)
{
    this->nodeMap[index] = node;
}

bool Graph::addEdge(uint32_t from, uint32_t to, uint32_t distance){
    if (from >= HASH_MAP_SIZE || to >= HASH_MAP_SIZE)
    {
        return false;
    }

    Node* fromNode = this->nodeMap[from];
    Node* toNode = this->nodeMap[to];

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

    Edge* edge = new Edge(toNode, distance);
    edge->setNext(fromNode->getHead());
    fromNode->setHead(edge);

    return true;
}

Graph::Graph(Graph&& other) noexcept 
    : numNodes(other.numNodes), head(other.head) {
    std::memcpy(nodeMap, other.nodeMap, sizeof(nodeMap));
    other.head = nullptr;
    other.numNodes = 0;
    std::memset(other.nodeMap, 0, sizeof(other.nodeMap));
}

Graph& Graph::operator=(Graph&& other) noexcept {
    if (this != &other) {
        Node* current = head;
        while (current) {
            Node* nextNode = current->getNext();
            delete current;
            current = nextNode;
        }

        numNodes = other.numNodes;
        head = other.head;
        std::memcpy(nodeMap, other.nodeMap, sizeof(nodeMap));

        other.head = nullptr;
        other.numNodes = 0;
        std::memset(other.nodeMap, 0, sizeof(other.nodeMap));
    }
    return *this;
}
