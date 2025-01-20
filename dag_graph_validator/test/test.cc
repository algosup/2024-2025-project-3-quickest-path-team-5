/*!
    \file
    \brief This file contains the tests for all DAG graph validator functions
    \authors CHARLES Rémy, CARON Maxime
*/

#include "gtest/gtest.h"
#include "graphLib.h"

#define BIG_SIZE 10000

/***********************************************************************
 * Graph Test
 ***********************************************************************/

bool insertNodesSmallAmount(graph_t* graph) {
    for (uint32_t i = 0; i < 10; ++i) {
        if (!addEdge(graph, i, i+1, 1)) {
            return false;
        }
    }
    return true;
}

bool insertNodesLargeAmount(graph_t* graph) {
    for (uint32_t i = 0; i < BIG_SIZE; ++i) {
        if (!addEdge(graph, i, i+1, 1)) {
            return false;
        }
    }
    return true;
}

TEST(GraphTest, CreateGraph) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    freeGraph(graph);
}

TEST(GraphTest, AddEdge) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    ASSERT_TRUE(addEdge(graph, 1, 2, 1));
    freeGraph(graph);
}

TEST(GraphTest, AddEdgeSmallAmount) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    ASSERT_TRUE(insertNodesSmallAmount(graph));
    freeGraph(graph);
}

TEST(GraphTest, AddEdgeLargeAmount) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    ASSERT_TRUE(insertNodesLargeAmount(graph));
    freeGraph(graph);
}

/***********************************************************************
 * Cycle Test
 ***********************************************************************/

TEST(CycleTest, NoCycle) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    ASSERT_TRUE(insertNodesSmallAmount(graph));
    ASSERT_TRUE(isDAG(graph));
    freeGraph(graph);
}

TEST(CycleTest, CycleExists) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    ASSERT_TRUE(insertNodesSmallAmount(graph));
    ASSERT_TRUE(addEdge(graph, 10, 0, 1)); // Creating a cycle
    ASSERT_FALSE(isDAG(graph));
    freeGraph(graph);
}

/***********************************************************************
 * Connectivity Test
 ***********************************************************************/

TEST(ConnectivityTest, AllNodesConnected) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    ASSERT_TRUE(insertNodesSmallAmount(graph));
    addEdge(graph, 10, 0, 1);
    ASSERT_TRUE(areAllNodesAccessible(graph));
    freeGraph(graph);
}

TEST(ConnectivityTest, NotAllNodesConnected) {
    graph_t* graph = createGraph();
    ASSERT_NE(graph, nullptr);
    ASSERT_TRUE(insertNodesSmallAmount(graph));
    ASSERT_TRUE(addEdge(graph, 11, 20, 1));
    ASSERT_FALSE(areAllNodesAccessible(graph));
    freeGraph(graph);
}

/***********************************************************************
 * Run all tests
 ***********************************************************************/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
