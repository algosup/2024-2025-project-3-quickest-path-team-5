/*!
    \file treeLib.h
    \brief Tree library
    \authors CHARLES Rémy, CARON Maxime
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /*!
        \typedef TreeNodeType
        \brief A struct representing a node in a tree
    */
    typedef struct TreeNode
    {
        unsigned long data;
        struct TreeNode *left;
        struct TreeNode *right;
    } TreeNodeType;

    /*!
        \typedef tree
        \brief A struct representing a tree
    */
    typedef struct Tree
    {
        TreeNodeType *root;
    } TreeType;

    /*!
        \brief Create a tree
        \param self The tree to create
     */
    void treeCreate(TreeType *self);

    /*!
        \brief Destroy a tree
        \param self The tree to destroy
     */
    void treeDestroy(TreeType *self);

    /*!
        \brief Tell if a tree is empty
        \param self The tree to check
        \return True if the tree is empty, false otherwise
     */
    bool treeEmpty(const TreeType *self);

    /*!
        \brief Get the number of nodes in the tree
        \param self The tree to check
        \return The number of nodes in the tree
     */
    size_t treeSize(const TreeType *self);

    /*!
        \brief Get the height of the tree
        \param self The tree to check
        \return The height of the tree
     */
    size_t treeHeight(const TreeType *self);

    /*!
        \brief Tell if a tree contains a value
        \param self The tree to check
        \param value The value to look for
        \return True if the value is in the tree, false otherwise
     */
    bool treeContains(const TreeType *self, unsigned long value);

    /*!
        \brief Insert a value in the tree and return false if the value was already present
        \param self The tree to insert the value in
        \param value The value to insert
        \return True if the value was inserted, false otherwise
     */
    bool treeInsert(TreeType *self, unsigned long value);

    /*!
        \brief Remove a value from the tree and return false if the value was not present
        \param self The tree to remove the value from
        \param value The value to remove
        \return True if the value was removed, false otherwise
     */
    bool treeRemove(TreeType *self, unsigned long value);

    /*!
        \brief Function type to walk in the tree
        \param value The value of the node
        \param user_data The data to pass to the function
     */
    typedef void (*treeFuncT)(unsigned long value, void *userData);

    /*!
        \brief Walk in the tree in pre order and call the function with user_data as a second argument
        \param self The tree to walk in
        \param func The function to call
        \param user_data The data to pass to the function
     */
    void treeWalkPreOrder(const TreeType *self, treeFuncT func, void *user_data);

    /*!
        \brief Walk in the tree in in order and call the function with user_data as a second argument
        \param self The tree to walk in
        \param func The function to call
        \param user_data The data to pass to the function
     */
    void treeWalkInOrder(const TreeType *self, treeFuncT func, void *user_data);

    /*!
        \brief Walk in the tree in post order and call the function with user_data as a second argument
        \param self The tree to walk in
        \param func The function to call
        \param user_data The data to pass to the function
     */
    void treeWalkPostOrder(const TreeType *self, treeFuncT func, void *user_data);

#ifdef __cplusplus
}
#endif
