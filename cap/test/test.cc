/*!
    \file
    \brief This file contains the tests for all functions of CAP application
    \authors CHARLES Rémy, CARON Maxime
*/

#include "gtest/gtest.h"
#include "./src/cap.cpp"

/***********************************************************************
 * Test Node
 ***********************************************************************/

TEST(NodeTest, createNode) {
    Node *node = new Node(1);
    ASSERT_NE(node, nullptr);
}

TEST(NodeTest, addEdgeSorted) {
    Node *node = new Node(1);
    node->addEdgeSorted(2, 1);
    ASSERT_EQ(node->edges[0].destID, 2);
}

/***********************************************************************
 * Test Edge
 ***********************************************************************/

TEST(EdgeTest, createEdge) {
    Edge *edge = new Edge(1, 1);
    ASSERT_NE(edge, nullptr);
}

/***********************************************************************
 * Test Graph
 ***********************************************************************/

TEST(GraphTest, creatGraph) {
    Graph *graph = new Graph();
    ASSERT_NE(graph, nullptr);
}

TEST(GraphTest, addEdge) {
    Graph *graph = new Graph();
    ASSERT_TRUE(graph->addEdge(1, 2, 1));
}

TEST(GraphTest, addLandmark) {
    Graph *graph = new Graph();
    ASSERT_TRUE(graph->addLandmark(1));
}

TEST(GraphTest, loadDataset) {
    Graph *graph = new Graph();
    loadDataset(graph, FILE_PATH);
    ASSERT_NE(graph, nullptr);
}

TEST(GraphTest, dijkstraFromTo) {
    uint32_t from = 1;
    uint32_t to = 22382040;
    Graph *graph = new Graph();
    loadDataset(graph, FILE_PATH);
    graph->selectLandmarks(16);
    ASSERT_ANY_THROW(graph->dijkstra(from, to));
}

TEST(GraphTest, dijkstraToFrom) {
    uint32_t from = 1;
    uint32_t to = 22382040;
    Graph *graph = new Graph();
    loadDataset(graph, FILE_PATH);
    graph->selectLandmarks(16);
    ASSERT_ANY_THROW(graph->dijkstra(to, from));
}

TEST(GraphTest, aStarFromTo) {
    uint32_t from = 1;
    uint32_t to = 22382040;
    Graph *graph = new Graph();
    loadDataset(graph, FILE_PATH);
    graph->selectLandmarks(16);
    ASSERT_ANY_THROW(graph->aStarLandmark(from, to));
}

TEST(GraphTest, aStarToFrom) {
    uint32_t from = 1;
    uint32_t to = 22382040;
    Graph *graph = new Graph();
    loadDataset(graph, FILE_PATH);
    graph->selectLandmarks(16);
    ASSERT_ANY_THROW(graph->aStarLandmark(to, from));
}

/***********************************************************************
 * Run all tests
 ***********************************************************************/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
