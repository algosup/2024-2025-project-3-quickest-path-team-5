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

/*!
    \brief Graph library checkings
*/

/*!
    \brief Graph creation
*/
TEST(GraphTest, GraphCreation) {
    GraphType graph;
    graphCreate(&graph);

    ASSERT_EQ(graph.num_nodes, static_cast<size_t>(0)) << "Graph should have no nodes initially.";
    ASSERT_EQ(graph.nodes, nullptr) << "Graph nodes array should be null.";
    ASSERT_EQ(graph.node_lookup, nullptr) << "Node lookup table should be null.";
    ASSERT_EQ(graph.is_directed, false) << "Graph should be undirected by default.";
    ASSERT_EQ(graph.is_weighted, false) << "Graph should be unweighted by default.";
    ASSERT_EQ(graph.max_degree, static_cast<size_t>(0)) << "Maximum degree should be zero initially.";

    graphDestroy(&graph);
}

/*!
    \brief Graph node creation
*/
TEST(GraphTest, GraphNodeCreation)
{
  GraphType graph;
  graphCreate(&graph);

  graphCreateNode(&graph, static_cast<uint32_t>(1));
  ASSERT_EQ(graph.num_nodes, static_cast<size_t>(1)) << "Graph should have one node.";
  ASSERT_NE(graph.nodes, nullptr) << "Graph nodes array should not be null.";
  ASSERT_NE(graph.node_lookup, nullptr) << "Node lookup table should not be null.";
  ASSERT_EQ(graph.is_directed, false) << "Graph should be undirected by default.";
  ASSERT_EQ(graph.is_weighted, false) << "Graph should be unweighted by default.";
  ASSERT_EQ(graph.max_degree, static_cast<size_t>(0)) << "Maximum degree should be zero initially.";

  graphDestroy(&graph);
}

/*!
    \brief Graph node creation
*/
TEST(GraphTest, GraphNodeCreationBig)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, static_cast<uint32_t>(i));
  }
  ASSERT_EQ(graph.num_nodes, static_cast<size_t>(BIG_SIZE)) << "Graph should have " << BIG_SIZE << " nodes.";
  ASSERT_NE(graph.nodes, nullptr) << "Graph nodes array should not be null.";
  ASSERT_NE(graph.node_lookup, nullptr) << "Node lookup table should not be null.";
  ASSERT_EQ(graph.is_directed, false) << "Graph should be undirected by default.";
  ASSERT_EQ(graph.is_weighted, false) << "Graph should be unweighted by default.";
  ASSERT_EQ(graph.max_degree, static_cast<size_t>(0)) << "Maximum degree should be zero initially.";

  graphDestroy(&graph);
}

/*!
    \brief Graph node creation with node already in graph
*/
TEST(GraphTest, GraphNodeCreationAlreadyInGraph)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  ASSERT_EQ(graph.num_nodes, static_cast<size_t>(1));
  ASSERT_NE(graph.nodes, nullptr) << "Graph nodes array should not be null.";
  ASSERT_NE(graph.node_lookup, nullptr) << "Node lookup table should not be null.";
  ASSERT_EQ(graph.is_directed, false) << "Graph should be undirected by default.";
  ASSERT_EQ(graph.is_weighted, false) << "Graph should be unweighted by default.";
  ASSERT_EQ(graph.max_degree, static_cast<size_t>(0)) << "Maximum degree should be zero initially.";

  graphDestroy(&graph);
}


/*!
    \brief Graph link creation
*/
TEST(GraphTest, GraphLinkCreation)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  graphCreateNode(&graph, static_cast<uint32_t>(2));
  createLink(&graph, static_cast<uint32_t>(1), static_cast<uint32_t>(2), static_cast<uint32_t>(1));
  ASSERT_EQ(graph.nodes[0]->num_links, static_cast<size_t>(1)) << "Parent node should have one link.";
  ASSERT_EQ(graph.nodes[1]->num_links, static_cast<size_t>(1)) << "Child node should have one link.";
  ASSERT_EQ(graph.nodes[0]->childs[0].node->id, static_cast<uint32_t>(2)) << "Parent node should have child node 2.";
  ASSERT_EQ(graph.nodes[1]->parents[0].node->id, static_cast<uint32_t>(1)) << "Child node should have parent node 1.";

  graphDestroy(&graph);
}

/*!
    \brief Graph link creation big
*/
TEST(GraphTest, GraphLinkCreationBig)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, static_cast<uint32_t>(i));
  }
  for (size_t i = 0; i < BIG_SIZE - 1; i++)
  {
    createLink(&graph, static_cast<uint32_t>(i), static_cast<uint32_t>(i + 1), static_cast<uint32_t>(1));
  }
  for (size_t i = 0; i < BIG_SIZE - 1; i++)
  {
    ASSERT_EQ(graph.nodes[i]->num_links, static_cast<size_t>(1)) << "Parent node should have one link.";
    ASSERT_EQ(graph.nodes[i + 1]->num_links, static_cast<size_t>(1)) << "Child node should have one link.";
    ASSERT_EQ(graph.nodes[i]->childs[0].node->id, static_cast<uint32_t>(i + 1)) << "Parent node should have child node " << i + 1;
    ASSERT_EQ(graph.nodes[i + 1]->parents[0].node->id, static_cast<uint32_t>(i)) << "Child node should have parent node " << i;
  }

  graphDestroy(&graph);
}

/*!
    \brief Graph link creation with node not in graph
*/
TEST(GraphTest, GraphLinkCreationNotInGraph)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  graphCreateNode(&graph, static_cast<uint32_t>(2));
  createLink(&graph, static_cast<uint32_t>(1), static_cast<uint32_t>(3), static_cast<uint32_t>(1));
  ASSERT_EQ(graph.nodes[0]->num_links, static_cast<size_t>(0)) << "Parent node should have no link.";
  ASSERT_EQ(graph.nodes[1]->num_links, static_cast<size_t>(0)) << "Child node should have no link.";

  graphDestroy(&graph);
}

/*!
    \brief Graph link creation with link already in graph
*/
TEST(GraphTest, GraphLinkCreationAlreadyInGraph)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  graphCreateNode(&graph, static_cast<uint32_t>(2));
  createLink(&graph, static_cast<uint32_t>(1), static_cast<uint32_t>(2), static_cast<uint32_t>(1));
  createLink(&graph, static_cast<uint32_t>(1), static_cast<uint32_t>(2), static_cast<uint32_t>(1));
  ASSERT_EQ(graph.nodes[0]->num_links, static_cast<size_t>(1)) << "Parent node should have one link.";
  ASSERT_EQ(graph.nodes[1]->num_links, static_cast<size_t>(1)) << "Child node should have one link.";

  graphDestroy(&graph);
}

/*!
    \brief Graph node removal
*/
TEST(GraphTest, GraphNodeRemoval)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  graphCreateNode(&graph, static_cast<uint32_t>(2));
  graphRemoveNode(&graph, static_cast<uint32_t>(1));
  ASSERT_EQ(graph.num_nodes, static_cast<size_t>(1)) << "Graph should have one node.";
  ASSERT_EQ(graph.nodes[0]->id, static_cast<uint32_t>(2)) << "Graph should have node 2.";
  ASSERT_EQ(graph.node_lookup[1], nullptr) << "Node lookup table should not have node 1.";

  graphDestroy(&graph);
}

/*!
    \brief Graph node removal big
*/
TEST(GraphTest, GraphNodeRemovalBig)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, static_cast<uint32_t>(i));
  }
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphRemoveNode(&graph, static_cast<uint32_t>(i));
  }
  ASSERT_EQ(graph.num_nodes, static_cast<size_t>(0)) << "Graph should have no nodes.";

  graphDestroy(&graph);
}

/*!
    \brief Graph node removal with node not in graph
*/
TEST(GraphTest, GraphNodeRemovalNotInGraph)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  graphCreateNode(&graph, static_cast<uint32_t>(2));
  graphRemoveNode(&graph, static_cast<uint32_t>(3));
  ASSERT_EQ(graph.num_nodes, static_cast<size_t>(2)) << "Graph should have two nodes.";

  graphDestroy(&graph);
}

/*!
    \brief Graph node removal with link
*/
TEST(GraphTest, GraphNodeRemovalWithLink)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, static_cast<uint32_t>(1));
  graphCreateNode(&graph, static_cast<uint32_t>(2));
  createLink(&graph, static_cast<uint32_t>(1), static_cast<uint32_t>(2), static_cast<uint32_t>(1));
  graphRemoveNode(&graph, static_cast<uint32_t>(1));
  ASSERT_EQ(graph.num_nodes, static_cast<size_t>(1)) << "Graph should have one node.";
  ASSERT_EQ(graph.nodes[0]->id, static_cast<uint32_t>(2)) << "Graph should have node 2.";
  ASSERT_EQ(graph.node_lookup[1], nullptr) << "Node lookup table should not have node 1.";

  graphDestroy(&graph);
}

/*!
    \brief Graph link removal
*/
TEST(GraphTest, GraphLinkRemoval)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  graphCreateNode(&graph, 2);
  createLink(&graph, 1, 2, 1);
  removeLink(&graph, 1, 2);
  ASSERT_EQ(graph.nodes[0]->num_links, 0);
  ASSERT_EQ(graph.nodes[1]->num_links, 0);

  graphDestroy(&graph);
}

/*!
    \brief Graph link removal big
*/
TEST(GraphTest, GraphLinkRemovalBig)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, i);
  }
  for (size_t i = 0; i < BIG_SIZE - 1; i++)
  {
    createLink(&graph, i, i + 1, 1);
  }
  for (size_t i = 0; i < BIG_SIZE - 1; i++)
  {
    removeLink(&graph, i, i + 1);
    ASSERT_EQ(graph.nodes[i]->num_links, 0);
    ASSERT_EQ(graph.nodes[i + 1]->num_links, 0);
  }

  graphDestroy(&graph);
}

/*!
    \brief Graph link removal with link not in graph
*/
TEST(GraphTest, GraphLinkRemovalNotInGraph)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  graphCreateNode(&graph, 2);
  createLink(&graph, 1, 2, 1);
  removeLink(&graph, 1, 3);
  ASSERT_EQ(graph.nodes[0]->num_links, 1);
  ASSERT_EQ(graph.nodes[1]->num_links, 0);

  graphDestroy(&graph);
}

/*!
    \brief Graph link removal with node not in graph
*/
TEST(GraphTest, GraphLinkRemovalNodeNotInGraph)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  graphCreateNode(&graph, 2);
  createLink(&graph, 1, 2, 1);
  removeLink(&graph, 1, 3);
  ASSERT_EQ(graph.nodes[0]->num_links, 1);
  ASSERT_EQ(graph.nodes[1]->num_links, 0);

  graphDestroy(&graph);
}

/*! 
    \brief Graph loop detection
*/
TEST(GraphTest, GraphLoopDetection)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  graphCreateNode(&graph, 2);
  createLink(&graph, 1, 2, 1);
  createLink(&graph, 2, 1, 1);
  ASSERT_TRUE(hasLoop(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph loop detection big
*/
TEST(GraphTest, GraphLoopDetectionBig)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, i);
  }
  for (size_t i = 0; i < BIG_SIZE - 1; i++)
  {
    createLink(&graph, i, i + 1, 1);
  }
  createLink(&graph, BIG_SIZE - 1, 0, 1);
  ASSERT_TRUE(hasLoop(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph loop detection with no loop
*/
TEST(GraphTest, GraphLoopDetectionNoLoop)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, i);
  }
  for (size_t i = 0; i < BIG_SIZE - 1; i++)
  {
    createLink(&graph, i, i + 1, 1);
  }
  ASSERT_FALSE(hasLoop(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph loop detection with no node
*/
TEST(GraphTest, GraphLoopDetectionNoNode)
{
  GraphType graph;
  graphCreate(&graph);
  ASSERT_FALSE(hasLoop(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph loop detection with no link
*/
TEST(GraphTest, GraphLoopDetectionNoLink)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  ASSERT_FALSE(hasLoop(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph check if all nodes are reachable
*/
TEST(GraphTest, GraphReachable)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  graphCreateNode(&graph, 2);
  createLink(&graph, 1, 2, 1);
  ASSERT_TRUE(areAllNodesReachable(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph check if all nodes are reachable big
*/
TEST(GraphTest, GraphReachableBig)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, i);
  }
  for (size_t i = 0; i < BIG_SIZE - 1; i++)
  {
    createLink(&graph, i, i + 1, 1);
  }
  ASSERT_TRUE(areAllNodesReachable(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph check if all nodes are reachable with no node
*/
TEST(GraphTest, GraphReachableNoNode)
{
  GraphType graph;
  graphCreate(&graph);
  ASSERT_FALSE(areAllNodesReachable(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph check if all nodes are reachable with no link
*/
TEST(GraphTest, GraphReachableNoLink)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  ASSERT_FALSE(areAllNodesReachable(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph check if all nodes are reachable with no reachable node
*/
TEST(GraphTest, GraphReachableNoReachableNode)
{
  GraphType graph;
  graphCreate(&graph);
  graphCreateNode(&graph, 1);
  graphCreateNode(&graph, 2);
  ASSERT_FALSE(areAllNodesReachable(&graph));

  graphDestroy(&graph);
}

/*! 
    \brief Graph check if all nodes are reachable with no reachable node big
*/
TEST(GraphTest, GraphReachableNoReachableNodeBig)
{
  GraphType graph;
  graphCreate(&graph);
  for (size_t i = 0; i < BIG_SIZE; i++)
  {
    graphCreateNode(&graph, i);
  }
  ASSERT_FALSE(areAllNodesReachable(&graph));

  graphDestroy(&graph);
}


int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}