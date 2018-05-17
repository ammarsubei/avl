/**
 *  @brief AVL class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <memory>

// Forward declaration of templated class Node
template<typename T> class Node;

/**
 *  @brief AVL class
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
     *  @brief Getter for current size of tree
     *  @return int size
     */
    int getSize()             const { return size; }

    /**
     *  @brief Getter for current height of tree
     *  @return int height
     */
    int getHeight()           const { return root->getHeight(); }

    /**
     *  @brief Setter for current size of tree
     *  @param int size
     */
    void setSize(const int newSize) { size = newSize; }

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
