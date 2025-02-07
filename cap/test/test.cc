/*!
    \file
    \brief This file contains the tests for all functions of CAP application
    \authors CHARLES Rémy, CARON Maxime
*/

#include "gtest/gtest.h"
#include "graph.hpp"
#include "csv_reader.hpp"
#include <time.h>
#include <cstring>

#define FILE_PATH "../../data/USA-roads.csv"

/***********************************************************************
 * Test Node
 ***********************************************************************/

TEST(NodeTest, createNode)
{
    Node *node = new Node(1);
    ASSERT_NE(node, nullptr);
}

TEST(NodeTest, addEdgeSorted)
{
    Node *node = new Node(1);
    node->addEdgeSorted(2, 1);
    ASSERT_EQ(node->edges[0].destID, (uint32_t)2);
}

/***********************************************************************
 * Test Edge
 ***********************************************************************/

TEST(EdgeTest, createEdge)
{
    Edge *edge = new Edge(1, 1);
    ASSERT_NE(edge, nullptr);
}

/***********************************************************************
 * Test Graph
 ***********************************************************************/

void insertEdgesIntoGraph1(Graph *graph)
{
    for (uint32_t i = 0; i < 20; i++)
        graph->addEdge(i, i + 1, 1);
}

void insertEdgesIntoGraph2(Graph *graph)
{
    for (uint32_t i = 0; i < 20; i++)
        graph->addEdge(i + 1, i, 1);
}

TEST(GraphTest, creatGraph)
{
    Graph *graph = new Graph();
    ASSERT_NE(graph, nullptr);
}

TEST(GraphTest, addEdge)
{
    Graph *graph = new Graph();
    ASSERT_TRUE(graph->addEdge(1, 2, 1));
}

TEST(GraphTest, addLandmark)
{
    Graph *graph = new Graph();
    ASSERT_TRUE(graph->addLandmark(1));
}

TEST(GraphTest, dataSetExist)
{
    FILE *file = fopen(FILE_PATH, "r");
    ASSERT_TRUE(file);
}

TEST(GraphTest, dijkstraFromTo)
{
    uint32_t from = 1;
    uint32_t to = 13;
    Graph *graph = new Graph();
    insertEdgesIntoGraph1(graph);
    graph->selectLandmarks(16);
    std::vector<uint32_t> expected_path = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    ASSERT_EQ(graph->dijkstra(from, to), expected_path);
}

TEST(GraphTest, dijkstraToFrom)
{
    uint32_t from = 1;
    uint32_t to = 13;
    Graph *graph = new Graph();
    insertEdgesIntoGraph1(graph);
    graph->selectLandmarks(16);
    std::vector<uint32_t> expected_path = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ASSERT_EQ(graph->dijkstra(to, from), expected_path);
}

TEST(GraphTest, aStarFromTo)
{
    uint32_t from = 1;
    uint32_t to = 13;
    Graph *graph = new Graph();
    insertEdgesIntoGraph1(graph);
    graph->selectLandmarks(16);
    std::vector<uint32_t> expected_path = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    ASSERT_EQ(graph->aStarLandmark(from, to), expected_path);
}

TEST(GraphTest, aStarToFrom)
{
    uint32_t from = 1;
    uint32_t to = 13;
    Graph *graph = new Graph();
    insertEdgesIntoGraph1(graph);
    graph->selectLandmarks(16);
    std::vector<uint32_t> expected_path = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ASSERT_EQ(graph->aStarLandmark(to, from), expected_path);
}

TEST(GraphTest, aStarSpeedTest)
{
    const char *defaultFilePath = FILE_PATH;
    char buffer[512];
    std::strcpy(buffer, defaultFilePath);
    ASSERT_TRUE(checkFileExists(buffer));
    Graph *graph = new Graph();
    loadDataset(graph, buffer);
    graph->selectLandmarks(16);
    clock_t begin = clock();
    std::vector<uint32_t> res = graph->aStarLandmark(9588784, 2720178); // Longuest path to process we kwow
    clock_t end = clock();
    ASSERT_GT(res.size(),(size_t) 0);
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    ASSERT_LT(time_spent, 1);
    begin = clock();
    res = graph->aStarLandmark(9489093, 22377087); // Longuest path we kwow
    end = clock();
    ASSERT_GT(res.size(),(size_t) 0);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    ASSERT_LT(time_spent, 1);
}

/***********************************************************************
 * Run all tests
 ***********************************************************************/

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
