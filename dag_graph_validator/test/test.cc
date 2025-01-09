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
#include "treeLib.h"
#include "graphLib.h"

#define BIG_SIZE 30000000

/***********************************************************************
 * Control Test
 ***********************************************************************/

TEST(ExampleTest, Example)
{
  ASSERT_EQ(1, 1);
}

/***********************************************************************
 * Tree Test
 ***********************************************************************/

/*!
    \brief Tree library checkings
 */

/*!
    \brief treeCreate
 */

TEST(TreeCreateTest, Empty)
{
  TreeType t;

  treeCreate(&t);

  EXPECT_TRUE(treeEmpty(&t));
  EXPECT_EQ(treeSize(&t), 0u);
  EXPECT_EQ(treeHeight(&t), 0u);

  treeDestroy(&t);
}

/*!
    \brief treeInsert
 */

TEST(TreeInsertTest, OneElement)
{
  TreeType t;

  treeCreate(&t);
  bool inserted = treeInsert(&t, 0);

  EXPECT_TRUE(inserted);
  EXPECT_FALSE(treeEmpty(&t));
  EXPECT_EQ(treeSize(&t), 1u);
  EXPECT_EQ(treeHeight(&t), 1u);
  EXPECT_TRUE(treeContains(&t, 0));

  treeDestroy(&t);
}

TEST(TreeInsertTest, TwoElements)
{
  TreeType t;

  treeCreate(&t);
  bool inserted1 = treeInsert(&t, 1);
  bool inserted2 = treeInsert(&t, 2);

  EXPECT_TRUE(inserted1);
  EXPECT_TRUE(inserted2);
  EXPECT_FALSE(treeEmpty(&t));
  EXPECT_EQ(treeSize(&t), 2u);
  EXPECT_EQ(treeHeight(&t), 2u);
  EXPECT_TRUE(treeContains(&t, 1));
  EXPECT_TRUE(treeContains(&t, 2));

  treeDestroy(&t);
}

TEST(TreeInsertTest, AlreadyPresent)
{
  TreeType t;
  treeCreate(&t);

  bool inserted1 = treeInsert(&t, 5);

  EXPECT_TRUE(inserted1);

  bool inserted2 = treeInsert(&t, 7);

  EXPECT_TRUE(inserted2);

  bool inserted3 = treeInsert(&t, 7); // already present

  EXPECT_FALSE(inserted3);
  EXPECT_FALSE(treeEmpty(&t));
  EXPECT_EQ(treeSize(&t), 2u);
  EXPECT_EQ(treeHeight(&t), 2u);
  EXPECT_TRUE(treeContains(&t, 5));
  EXPECT_TRUE(treeContains(&t, 7));

  treeDestroy(&t);
}

TEST(TreeInsertTest, ManyElements)
{
  static const int values[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (std::size_t i = 0; i < std::size(values); ++i)
  {
    bool inserted = treeInsert(&t, values[i]);
    EXPECT_TRUE(inserted);
  }

  for (std::size_t i = 0; i < std::size(values); ++i)
  {
    EXPECT_TRUE(treeContains(&t, values[i]));
  }

  for (int i = 1; i <= 19; i += 2)
  {
    EXPECT_FALSE(treeContains(&t, i));
  }

  treeDestroy(&t);
}

static size_t log_2(size_t x)
{
  size_t res = 0;

  while (x != 0)
  {
    res++;
    x /= 2;
  }

  return res;
}

TEST(TreeInsertTest, Stressed)
{
  TreeType t;
  treeCreate(&t);

  std::size_t expected = 0;
  std::srand(0);

  for (size_t i = 0; i < BIG_SIZE; ++i)
  {
    int value = std::rand();

    if (treeInsert(&t, value))
    {
      ++expected;
    }

    EXPECT_EQ(treeSize(&t), expected);
  }

  EXPECT_FALSE(treeEmpty(&t));

  size_t size = treeSize(&t);
  size_t height = treeHeight(&t);

  EXPECT_EQ(size, expected);
  EXPECT_LE(height, size);
  EXPECT_LE(log_2(size + 1), height);

  treeDestroy(&t);
}

/*!
    \brief treeRemove
*/

TEST(TreeRemoveTest, ManyElements)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (int val : origin)
  {
    treeInsert(&t, val);
  }

  for (std::size_t i = 0; i < std::size(origin); ++i)
  {
    EXPECT_TRUE(treeContains(&t, origin[i]));

    bool removed = treeRemove(&t, origin[i]);

    EXPECT_TRUE(removed);
    EXPECT_FALSE(treeContains(&t, origin[i]));
    EXPECT_EQ(treeSize(&t), std::size(origin) - i - 1);
  }

  treeDestroy(&t);
}

TEST(TreeRemoveTest, NotPresentBefore)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (int val : origin)
  {
    treeInsert(&t, val);
  }

  bool removed = treeRemove(&t, 1);

  EXPECT_FALSE(removed);
  EXPECT_EQ(treeSize(&t), std::size(origin));

  treeDestroy(&t);
}

TEST(TreeRemoveTest, NotPresentMiddle)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (int val : origin)
  {
    treeInsert(&t, val);
  }

  bool removed = treeRemove(&t, 9);

  EXPECT_FALSE(removed);
  EXPECT_EQ(treeSize(&t), std::size(origin));

  treeDestroy(&t);
}

TEST(TreeRemoveTest, NotPresentAfter)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (int val : origin)
  {
    treeInsert(&t, val);
  }

  bool removed = treeRemove(&t, 19);

  EXPECT_FALSE(removed);
  EXPECT_EQ(treeSize(&t), std::size(origin));

  treeDestroy(&t);
}

TEST(TreeRemoveTest, Stressed)
{
  TreeType t;
  treeCreate(&t);

  std::srand(0);

  for (size_t i = 0; i < BIG_SIZE; ++i)
  {
    int value = rand();
    treeInsert(&t, value);
  }

  size_t expected = treeSize(&t);
  EXPECT_TRUE(expected > 0);

  std::srand(0); // reinit

  for (size_t i = 0; i < BIG_SIZE; ++i)
  {
    int value = rand();

    bool present = treeContains(&t, value);

    if (present)
    {
      --expected;
    }

    bool removed = treeRemove(&t, value);

    EXPECT_EQ(present, removed);
    EXPECT_EQ(treeSize(&t), expected);
  }

  EXPECT_EQ(treeSize(&t), 0u);

  treeDestroy(&t);
}

/*!
    \brief treeWalkInOrder
 */

static void checkTree(int value, void *userData)
{
  int *expected = static_cast<int *>(userData);

  ASSERT_TRUE(expected != NULL);
  EXPECT_EQ(*expected, value);

  (*expected) += 2;
}

TEST(TreeWalkInOrderTest, Ordered)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (std::size_t i = 0; i < std::size(origin); ++i)
  {
    treeInsert(&t, origin[i]);
  }

  EXPECT_EQ(treeSize(&t), std::size(origin));

  int expected = 2;
  treeWalkInOrder(&t, checkTree, &expected);
  EXPECT_EQ(expected, 20);

  treeDestroy(&t);
}

static void checkOnce(int value, void *userData)
{
  int *count = static_cast<int *>(userData);

  ASSERT_TRUE(count != NULL);
  ASSERT_TRUE(2 <= value && value <= 18);
  EXPECT_EQ(count[value / 2], 0);

  count[value / 2] = 1;
}

TEST(TreeWalkInOrderTest, Count)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (std::size_t i = 0; i < std::size(origin); ++i)
  {
    treeInsert(&t, origin[i]);
  }

  int count[10];

  std::memset(count, 0, sizeof count);
  treeWalkInOrder(&t, checkOnce, count);

  EXPECT_EQ(count[0], 0);

  for (std::size_t i = 1; i < std::size(count); ++i)
  {
    EXPECT_EQ(count[i], 1);
  }

  treeDestroy(&t);
}

/*!
    \brief treeWalkPostOrder
 */

TEST(TreeWalkPreOrderTest, Count)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (std::size_t i = 0; i < std::size(origin); ++i)
  {
    treeInsert(&t, origin[i]);
  }

  int count[10];

  std::memset(count, 0, sizeof count);
  treeWalkPreOrder(&t, checkOnce, count);

  EXPECT_EQ(count[0], 0);

  for (std::size_t i = 1; i < std::size(count); ++i)
  {
    EXPECT_EQ(count[i], 1);
  }

  treeDestroy(&t);
}

/*!
    \brief treeWalkPostOrder
 */

TEST(TreeWalkPostOrderTest, Count)
{
  static const int origin[] = {16, 2, 8, 4, 10, 18, 6, 12, 14};

  TreeType t;
  treeCreate(&t);

  for (std::size_t i = 0; i < std::size(origin); ++i)
  {
    treeInsert(&t, origin[i]);
  }

  int count[10];

  std::memset(count, 0, sizeof count);
  treeWalkPostOrder(&t, checkOnce, count);

  EXPECT_EQ(count[0], 0);

  for (std::size_t i = 1; i < std::size(count); ++i)
  {
    EXPECT_EQ(count[i], 1);
  }

  treeDestroy(&t);
}

/***********************************************************************
 * Graph Test
 ***********************************************************************/

/*!
    \brief Graph library checkings
*/

/*!
    \brief graphCreate
*/
TEST(GraphCreateTest, Empty)
{
  GraphType g;

  graphCreate(&g);

  EXPECT_TRUE(graphEmpty(&g));
  EXPECT_EQ(graphSize(&g), 0u);

  graphDestroy(&g);
}

/*!
    \brief graphInsert
*/

TEST(GraphInsertTest, OneElement)
{
  GraphType g;

  graphCreate(&g);
  bool inserted = graphInsert(&g, 0, 1, 2);

  EXPECT_TRUE(inserted);
  EXPECT_FALSE(graphEmpty(&g));
  EXPECT_EQ(graphSize(&g), 1u);
  EXPECT_TRUE(graphContains(&g, 1));

  graphDestroy(&g);
}

TEST(GraphInsertTest, TwoElements)
{
  GraphType g;

  graphCreate(&g);
  bool inserted1 = graphInsert(&g, 0, 1, 2);
  bool inserted2 = graphInsert(&g, 1, 2, 3);

  EXPECT_TRUE(inserted1);
  EXPECT_TRUE(inserted2);
  EXPECT_FALSE(graphEmpty(&g));
  EXPECT_EQ(graphSize(&g), 2u);
  EXPECT_TRUE(graphContains(&g, 1));
  EXPECT_TRUE(graphContains(&g, 2));

  graphDestroy(&g);
}

TEST(GraphInsertTest, AlreadyPresent)
{
  GraphType g;

  graphCreate(&g);

  bool inserted1 = graphInsert(&g, 0, 1, 2);
  bool inserted2 = graphInsert(&g, 1, 2, 3);
  bool inserted3 = graphInsert(&g, 0, 1, 2); // already present

  EXPECT_TRUE(inserted1);
  EXPECT_TRUE(inserted2);
  EXPECT_FALSE(inserted3);
  EXPECT_FALSE(graphEmpty(&g));
  EXPECT_EQ(graphSize(&g), 2u);
  EXPECT_TRUE(graphContains(&g, 1));
  EXPECT_TRUE(graphContains(&g, 2));

  graphDestroy(&g);
}

TEST(GraphInsertTest, ManyElements)
{
  static const std::array<std::array<int, 3>, 9> values = {{{0, 1, 2},
                                                            {1, 2, 3},
                                                            {2, 3, 4},
                                                            {3, 4, 5},
                                                            {4, 5, 6},
                                                            {5, 6, 7},
                                                            {6, 7, 8},
                                                            {7, 8, 9},
                                                            {8, 9, 10}}};

  GraphType g;
  graphCreate(&g);

  for (const auto &val : values)
  {
    bool inserted = graphInsert(&g, val[0], val[1], val[2]);
    EXPECT_TRUE(inserted);
  }

  for (const auto &val : values)
  {
    EXPECT_TRUE(graphContains(&g, val[1]));
  }

  graphDestroy(&g);
}

TEST(GraphInsertTest, Stressed)
{
  GraphType g;
  graphCreate(&g);

  std::srand(std::time(0));

  for (size_t i = 1; i <= BIG_SIZE; ++i)
  {
    size_t parentId = i - 1;
    size_t id = i;
    size_t distance = std::rand();

    graphInsert(&g, parentId, id, distance);
  }

  EXPECT_FALSE(graphEmpty(&g));

  size_t size = graphSize(&g);

  EXPECT_EQ(size, BIG_SIZE);

  graphDestroy(&g);
}

/*!
    \brief graphContains
*/

TEST(GraphContainsTest, Empty)
{
  GraphType g;

  graphCreate(&g);

  EXPECT_FALSE(graphContains(&g, 0));
  EXPECT_TRUE(graphEmpty(&g));

  graphDestroy(&g);
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}