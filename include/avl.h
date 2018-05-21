/**
 *  @file AVL class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <memory>

// Forward declaration of templated class Node
template<typename T> class Node;

/**
 *  @brief AVL class is a self-balancing binary search tree
 *
 *  There are four cases where a binary search tree needs balancing:
 *
 *  Case 1:
 *  ```
 *      C      B
 *     /      / \
 *    B  ==> A   C
 *   /
 *  A
 *  ```
 *  Case 2 (requires 2 rotations):
 *  ```
 *      C        C      B
 *     /        /      / \
 *    A  ==>   B  ==> A   C
 *     \      /
 *      B    A
 *  ```
 *  Case 3 (requires 2 rotations):
 *  ```
 *    A       A          B
 *     \       \        / \
 *      C ==>   B  ==> A   C
 *     /         \
 *    B           C
 *  ```
 *  Case 4:
 *  ```
 *  A          B
 *   \        / \
 *    B  ==> A   C
 *     \
 *      C
 *  ```
 */
template<typename T>
class AVL
{
  public:
    /**
     *  @brief Default constructor
     */
    AVL() : root(nullptr), size(0) {}

    /**
     *  @brief Destructor
     */
    ~AVL()                { if (root) delete root; }

    /**
     *  @brief Getter for current size of tree
     *  @return int size
     */
    int getSize()   const { return size; }

    /**
     *  @brief Getter for current height of tree
     *  @return int height
     */
    int getHeight() const { return root->getHeight(); }

    /**
     *  @brief Recursive inorder print
     */
    void print();

    /**
     *  @brief Adds new item to tree
     *  @param T new item
     */
    void add(T item);

    /**
     *  @brief Removes existing item from tree
     *  @param T item to remove
     */
    void remove(T item);

  private:
    /**
     *  @brief Helper function for inorder print
     */
    void _print(Node<T> *node);

  private:
    Node<T> *root;  ///< Root node
    int size;       ///< Size of tree
};
