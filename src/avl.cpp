/**
 *  @brief AVL class definitions
 *
 *  @author Ammar Subei
 */

#include <vector>
#include <string>
#include <iostream>

#include "avl.h"
#include "node.h"

template<typename T> 
void AVL<T>::_print(Node<T> *node)
{
  if (node) {
    _print(node->getLeft());
    std::cout << node->getData() << " ";
    _print(node->getRight());
  }
}

template<typename T> 
void AVL<T>::print()
{
  std::cout << "Printing AVL Tree In-Order:" << std::endl;
  _print(root);
  std::cout << std::endl;
}

template<typename T> 
void AVL<T>::add(T item)
{
  Node<T> *previous = nullptr;
  Node<T> *current = root;

  // Figure out where item should be added
  std::vector< Node<T>* > nodesTraversed;
  while (current) {
    nodesTraversed.push_back(current);

    // Gotta check if item already exists
    if (current->getData() == item) {
      return;
    } else if (current->getData() < item) {
      previous = current;
      current = current->getRight();
    } else {
      previous = current;
      current = current->getLeft();
    }
  }

  // At this point, item doesn't exist
  Node<T> *newNode = new Node<T>(item);

  if (!previous) {
    // Tree was empty, set root
    root = newNode;
    size = getSize() + 1;
    return;
  } else if (previous->getData() < newNode->getData()) {
    // New item is larger
    previous->setRight(newNode);
  } else {
    // New item is smaller
    previous->setLeft(newNode);
  }

  size = getSize() + 1;

  // Walk back up the tree and update heights when necessary
  // If height of a node doesn't change, then tree is balanced
  // If AVL condidtion is broken, raise unbalanced flag
  Node<T> *temp;
  bool balanced = true;

  while ( !nodesTraversed.empty() && balanced ) {
    temp = nodesTraversed.back();
    nodesTraversed.pop_back();

    const int oldHeight = temp->getHeight();
    balanced = temp->updateHeight();

    // Height of node didn't change, we're done here
    if (oldHeight == temp->getHeight()) {
      return;
    }
  }

  // Perform rotations to balance the tree
  if (!balanced) {
    current = temp;
    
    if (nodesTraversed.empty()) {
      previous = nullptr;
    } else {
      previous = nodesTraversed.back();
    }

    // Tree is left heavy (case 1 & 2)
    if (newNode->getData() < current->getData()) {
      Node<T> *L = current->getLeft();

      // Tree's left subtree is right heavy (case 2)
      if (newNode->getData() > L->getData()) {
        // Perform left rotation @L
        current->setLeft( L->leftRotate() );
      }

      // Perform right rotation @current
      if (previous == nullptr) {
        root = current->rightRotate();
      } else if (previous->getLeft() == current) {
        previous->setLeft( current->rightRotate() );
      } else {
        previous->setRight( current->rightRotate() );
      }
    } else {  // Tree is right heavy (case 3 & 4)
      Node<T> *R = current->getRight();

      // Tree's right subtree is left heavy (case 3)
      if (newNode->getData() < R->getData()) {
        // Perform right rotation @R
        current->setRight( R->rightRotate() );
      }

      // Perform left rotation @current
      if (previous == nullptr) {
        root = current->leftRotate();
      } else if (previous->getLeft() == current) {
        previous->setLeft( current->leftRotate() );
      } else {
        previous->setRight( current->leftRotate() );
      }
    }
  }
}

template<typename T> 
void AVL<T>::remove(T item)
{
  Node<T> *current = root;

  std::vector< Node<T>* > nodesTraversed;
  while (current) {
    nodesTraversed.push_back(current);

    if (current->getData() == item) {
      break;
    } else if (current->getData() < item) {
      current = current->getRight();
    } else {
      current = current->getLeft();
    }
  }

  // Return if item wasn't found
  if (!current) {
    return;
  }

  // TODO: Current node should be removed
  // Make sure to preserve node children

  // TODO: Rebalance tree as needed
}

template class AVL<int>;
template class AVL<float>;
template class AVL<double>;
template class AVL<std::string>;
