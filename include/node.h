/**
 *  @file Node class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <memory>

/**
 *  @brief Node class used for the AVL tree structure
 */
template<typename T>
class Node
{
  public:
    /**
     *  @brief Default constructor
     *  @param T initial data
     */
    Node(T newData) : data(newData), height(0), left(nullptr), right(nullptr) {}

    /**
     *  @brief Destructor
     */
    ~Node();

    /**
     *  @brief Getter for node data
     *  @return T node data
     */
    T getData()                   const { return data; }

    /**
     *  @brief Getter for node height
     *  @return int node height
     */
    int getHeight()               const { return height; }

    /**
     *  @brief Getter for left child node
     *  @return Node* left child
     */
    Node<T>* getLeft()            const { return left; }

    /**
     *  @brief Getter for right child node
     *  @return Node* right child
     */
    Node<T>* getRight()           const { return right; }

    /**
     *  @brief Setter for node data
     *  @param int new data
     */
    void setData(const T newData)       { data = newData; }

    /**
     *  @brief Setter for node height
     *  @param int new height
     */
    void setHeight(const int newHeight) { height = newHeight; }

    /**
     *  @brief Setter for left child node
     *  @param Node* left child
     */
    void setLeft(Node<T> *newLeft)      { left = newLeft; }

    /**
     *  @brief Setter for right child node
     *  @param Node* right child
     */
    void setRight(Node<T> *newRight)    { right = newRight; }

    /**
     *  @brief Updates height
     *
     *  Used after adding a new node to update heights and
     *  check if AVL condition was broken.
     *
     *  @return bool node is balanced
     */
    bool updateHeight();

    /**
     *  @brief Right rotation for balancing the tree
     *
     *  ```
     *      C      B
     *     /      / \
     *    B  ==> A   C
     *   /
     *  A
     *  ```
     *
     *  @return NodePtr new subTree root
     */
    Node<T>* rightRotate();

    /**
     *  @brief Left rotation for balancing the tree
     *
     *  ```
     *  A          B
     *   \        / \
     *    B  ==> A   C
     *     \
     *      C
     *  ```
     *
     *  @return NodePtr new subTree root
     */
    Node<T>* leftRotate();

  private:
    T data;         ///< Node data
    int height;     ///< Node height
    Node<T> *left;  ///< Left child
    Node<T> *right; ///< Right child
};
