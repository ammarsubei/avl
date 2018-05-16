/**
 *  @brief Node class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <memory>

/**
 *  @brief Node class
 */
template<typename T>
class Node
{
  public:
    typedef std::unique_ptr< Node<T> > NodePtr;

    /**
     *  @brief Default constructor
     *  @param T initial data
     */
    Node(T newData) : data(newData), height(0), left(nullptr), right(nullptr) {}

    /**
     *  @brief Getter of node data
     *  @return T node data
     */
    T getData()                   const { return data; }

    /**
     *  @brief Getter of node height
     *  @return int node height
     */
    int getHeight()               const { return height; }

    /**
     *  @brief Setter of node data
     *  @param int new data
     */
    void setData(const T newData)       { data = newData; }

    /**
     *  @brief Setter of node height
     *  @param int new height
     */
    void setHeight(const int newHeight) { height = newHeight; }

  private:
    /**
     *  @brief Setter of left child node
     *  @param NodePtr left node
     */
    void setLeft(const NodePtr& node)   { left = std::move(node); }

    /**
     *  @brief Setter of right child node
     *  @param NodePtr right node
     */
    void setRight(const NodePtr& node)  { right = std::move(node); }

    /**
     *  @brief Right rotation for balancing the tree
     *  @return NodePtr new subTree root
     *
     *         S           T
     *        / \         / \
     *       T   C  ==>  A   S
     *      / \             / \
     *     A   B           B   C
     *
     */
    NodePtr rightRotate();

    /**
     *  @brief Left rotation for balancing the tree
     *  @return NodePtr new subTree root
     *
     *         S           T
     *        / \         / \
     *       A   T  ==>  S   C
     *          / \     / \
     *         B   C   A   B
     *
     */
    NodePtr leftRotate();

  private:
    T data;         ///< Node data
    int height;     ///< Node height
    NodePtr left;   ///< Left child
    NodePtr right;  ///< Right child
};
