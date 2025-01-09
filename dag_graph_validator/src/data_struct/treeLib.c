#include "treeLib.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void treeCreate(TreeType *self)
{
  self->root = NULL;
}

TreeNodeType *treeDelMin(TreeNodeType *node, TreeNodeType **min)
{
  if (node->left == NULL)
  {
    TreeNodeType *right = node->right;
    node->right = NULL;
    *min = node;
    return right;
  }
  node->left = treeDelMin(node->left, min);
  return node;
}

TreeNodeType *treeDestroyPartial(TreeNodeType *node)
{
  TreeNodeType *left = node->left;
  TreeNodeType *right = node->right;
  free(node);
  node = NULL;
  if ((left == NULL) && (right == NULL))
  {
    return NULL;
  }
  if (left == NULL)
  {
    return right;
  }
  if (right == NULL)
  {
    return left;
  }
  right = treeDelMin(right, &node);
  node->left = left;
  node->right = right;
  return node;
}

void treeDestroy(TreeType *self)
{
  TreeNodeType *node;
  size_t size = treeSize(self);
  for (size_t i = 0; i < size; ++i)
  {
    node = self->root;
    self->root = treeDestroyPartial(node);
  }
}

bool treeNodeSearch(const TreeNodeType *self, int value)
{
  if (self == NULL)
  {
    return false;
  }
  if (value < self->data)
  {
    return treeNodeSearch(self->left, value);
  }
  if (value > self->data)
  {
    return treeNodeSearch(self->right, value);
  }
  return true;
}

bool treeContains(const TreeType *self, int value)
{
  return treeNodeSearch(self->root, value);
}

TreeNodeType *addNode(TreeNodeType *node, int value)
{
  if (node == NULL)
  {
    TreeNodeType *new = malloc(sizeof(TreeNodeType));
    new->left = new->right = NULL;
    new->data = value;
    return new;
  }
  if (value < node->data)
  {
    node->left = addNode(node->left, value);
  }
  else if (value > node->data)
  {
    node->right = addNode(node->right, value);
  }
  return node;
}

bool treeInsert(TreeType *self, int value)
{
  if (treeContains(self, value))
    return false;
  TreeNodeType *curr = self->root;
  self->root = addNode(curr, value);
  return true;
}

TreeNodeType *treeRemovePartial(TreeNodeType *node, int value)
{
  if (node == NULL)
  {
    return NULL;
  }
  if (value < node->data)
  {
    node->left = treeRemovePartial(node->left, value);
    return node;
  }
  if (value > node->data)
  {
    node->right = treeRemovePartial(node->right, value);
    return node;
  }
  return treeDestroyPartial(node);
}

bool treeRemove(TreeType *self, int value)
{
  if ((treeEmpty(self)) || (!treeContains(self, value)))
  {
    return false;
  }
  TreeNodeType *node = self->root;
  self->root = treeRemovePartial(node, value);
  return true;
}

bool treeEmpty(const TreeType *self)
{
  return (self->root == NULL);
}

size_t treeNodeNb(const TreeNodeType *node)
{
  if (node == NULL)
  {
    return 0;
  }
  return (treeNodeNb(node->left) + 1 + treeNodeNb(node->right));
}

size_t treeSize(const TreeType *self)
{
  return treeNodeNb(self->root);
}

size_t treeNodeHeight(const TreeNodeType *node)
{
  size_t sizeL = 0;
  size_t sizeR = 0;
  if (node->left != NULL)
  {
    sizeL = treeNodeNb(node->left);
  }
  if (node->right != NULL)
  {
    sizeR = treeNodeNb(node->right);
  }
  return (sizeL >= sizeR) ? (1 + sizeL) : (1 + sizeR);
}

size_t treeHeight(const TreeType *self)
{
  if (treeEmpty(self))
    return 0;
  else
    return treeNodeHeight(self->root);
}

void preOrderPartial(TreeNodeType *node, treeFuncT func, void *userData)
{
  func(node->data, userData);
  if (node->left != NULL)
  {
    preOrderPartial(node->left, func, userData);
  }
  if (node->right != NULL)
  {
    preOrderPartial(node->right, func, userData);
  }
}

void treeWalkPreOrder(const TreeType *self, treeFuncT func, void *userData)
{
  if (treeEmpty(self))
    return;
  else
  {
    preOrderPartial(self->root, func, userData);
  }
}

void inOrderPartial(TreeNodeType *node, treeFuncT func, void *userData)
{
  if (node->left != NULL)
  {
    inOrderPartial(node->left, func, userData);
  }
  func(node->data, userData);
  if (node->right != NULL)
  {
    inOrderPartial(node->right, func, userData);
  }
}

void treeWalkInOrder(const TreeType *self, treeFuncT func, void *userData)
{
  if (treeEmpty(self))
    return;
  else
  {
    inOrderPartial(self->root, func, userData);
  }
}

void postOrderPartial(TreeNodeType *node, treeFuncT func, void *userData)
{
  if (node->left != NULL)
  {
    postOrderPartial(node->left, func, userData);
  }
  if (node->right != NULL)
  {
    postOrderPartial(node->right, func, userData);
  }
  func(node->data, userData);
}

void treeWalkPostOrder(const TreeType *self, treeFuncT func, void *userData)
{
  if (treeEmpty(self))
    return;
  else
  {
    postOrderPartial(self->root, func, userData);
  }
}
