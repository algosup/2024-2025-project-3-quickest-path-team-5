/*!
    \file
    \brief Thie file contains the tests for all DAG graph validator functions
    \authors CHARLES Rémy, CARON Maxime
*/

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <array>
#include <ctime>

#include "gtest/gtest.h"
#include "graphLib.h"

#define BIG_SIZE 10000

/***********************************************************************
 * Control Test
 ***********************************************************************/

TEST(ExampleTest, Example)
{
  ASSERT_EQ(1, 1);
}

/***********************************************************************
 * Graph Test
 ***********************************************************************/

#include <gtest/gtest.h>
#include "graphLib.h"

// Test graph creation and destruction
TEST(GraphTest, GraphInitialization) {
    GraphType graph;
    graphCreate(&graph);

    EXPECT_EQ(graph.num_nodes, static_cast<size_t>(0)) << "Graph should start with no nodes.";
    EXPECT_EQ(graph.nodes, nullptr) << "Nodes pointer should be null initially.";
    EXPECT_EQ(graph.node_lookup, nullptr) << "Node lookup pointer should be null initially.";
    EXPECT_FALSE(graph.is_directed) << "Graph should be undirected by default.";
    EXPECT_FALSE(graph.is_weighted) << "Graph should be unweighted by default.";
    EXPECT_EQ(graph.max_degree, static_cast<size_t>(0)) << "Graph should have max degree of 0 initially.";

    graphDestroy(&graph);
}

// Test graphEmpty function
TEST(GraphTest, EmptyGraph) {
    GraphType graph;
    graphCreate(&graph);
    EXPECT_TRUE(graphEmpty(&graph)) << "Graph should be empty initially.";
    graphDestroy(&graph);
}

// Test adding a node
TEST(GraphTest, AddNode) {
    GraphType graph;
    graphCreate(&graph);

    uint32_t nodeId = 1;
    EXPECT_TRUE(graphCreateNode(&graph, nodeId)) << "Node creation should succeed.";
    EXPECT_EQ(graph.num_nodes, 1) << "Graph should have one node.";
    EXPECT_TRUE(graphContains(&graph, nodeId)) << "Graph should contain the added node.";

    graphDestroy(&graph);
}

// Test adding a link
TEST(GraphTest, AddLink) {
    GraphType graph;
    graphCreate(&graph);

    uint32_t nodeId1 = 1, nodeId2 = 2;
    graphCreateNode(&graph, nodeId1);
    graphCreateNode(&graph, nodeId2);

    EXPECT_TRUE(createLink(&graph, nodeId1, nodeId2, 10)) << "Link creation should succeed.";
    EXPECT_TRUE(linkExist(&graph, nodeId1, nodeId2)) << "Link should exist between the nodes.";

    graphDestroy(&graph);
}

// Test removing a node
TEST(GraphTest, RemoveNode) {
    GraphType graph;
    graphCreate(&graph);

    uint32_t nodeId = 1;
    graphCreateNode(&graph, nodeId);

    EXPECT_TRUE(graphRemoveNode(&graph, nodeId)) << "Node removal should succeed.";
    EXPECT_FALSE(graphContains(&graph, nodeId)) << "Graph should not contain the removed node.";

    graphDestroy(&graph);
}

// Test removing a link
TEST(GraphTest, RemoveLink) {
    GraphType graph;
    graphCreate(&graph);

    uint32_t nodeId1 = 1, nodeId2 = 2;
    graphCreateNode(&graph, nodeId1);
    graphCreateNode(&graph, nodeId2);
    createLink(&graph, nodeId1, nodeId2, 10);

    EXPECT_TRUE(removeLink(&graph, nodeId1, nodeId2)) << "Link removal should succeed.";
    EXPECT_FALSE(linkExist(&graph, nodeId1, nodeId2)) << "Link should not exist after removal.";

    graphDestroy(&graph);
}

// Test graph loop detection
TEST(GraphTest, DetectLoop) {
    GraphType graph;
    graphCreate(&graph);

    uint32_t nodeId1 = 1, nodeId2 = 2;
    graphCreateNode(&graph, nodeId1);
    graphCreateNode(&graph, nodeId2);
    createLink(&graph, nodeId1, nodeId2, 10);
    createLink(&graph, nodeId2, nodeId1, 10); // Creates a loop

    EXPECT_TRUE(hasLoop(&graph)) << "Graph should detect a loop.";

    graphDestroy(&graph);
}

// Test checking if all nodes are reachable
TEST(GraphTest, AllNodesReachable) {
    GraphType graph;
    graphCreate(&graph);

    uint32_t nodeId1 = 1, nodeId2 = 2;
    graphCreateNode(&graph, nodeId1);
    graphCreateNode(&graph, nodeId2);
    createLink(&graph, nodeId1, nodeId2, 10);

    EXPECT_TRUE(areAllNodesReachable(&graph)) << "All nodes should be reachable.";

    graphDestroy(&graph);
}

// Test graph with unreachable node
TEST(GraphTest, UnreachableNode) {
    GraphType graph;
    graphCreate(&graph);

    uint32_t nodeId1 = 1, nodeId2 = 2;
    graphCreateNode(&graph, nodeId1);
    graphCreateNode(&graph, nodeId2); // No link between nodeId1 and nodeId2

    EXPECT_FALSE(areAllNodesReachable(&graph)) << "Graph should detect an unreachable node.";

    graphDestroy(&graph);
}



int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}