/**
 *  @brief AVL class definitions
 *
 *  @author Ammar Subei
 */

#include <cmath>
#include <vector>
#include <string>
#include <iostream>

#include "avl.h"
#include "node.h"
#include "util.h"

template<typename T> 
void AVL<T>::_print(Node<T> *node)
{
}

template<typename T> 
void AVL<T>::print()
{
  std::cout << "root: " << root->getData() << std::endl;
}

template<typename T> 
void AVL<T>::add(T item)
{
  Node<T> *previous = nullptr;
  Node<T> *current = root;

  // Figure out where item should be added
  std::vector< Node<T>* > nodesTraverse;
  while (current) {
    nodesTraverse.push_back(current);

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
    setSize( getSize() + 1 );
    return;
  } else if (previous->getData() < newNode->getData()) {
    // New item is larger
    previous->setRight(newNode);
  } else {
    // New item is smaller
    previous->setLeft(newNode);
  }

  setSize( getSize() + 1 );

  // Walk back up the tree and update heights when necessary
  // If height of a node doesn't change, then tree is balanced
  // If AVL condidtion is broken, raise unbalanced flag
  Node<T> *temp;
  bool unbalanced = false;

  while ( !nodesTraverse.empty() ) {
    temp = nodesTraverse.back();
    nodesTraverse.pop_back();

    const int heightLeft = temp->getLeft()->getHeight();
    const int heightRight = temp->getRight()->getHeight();
    const int newHeight = 1 + max(heightLeft, heightRight);

    if ( std::abs(heightLeft - heightRight) > 1 ) {
      unbalanced = true;
      break;
    } else if (temp->getHeight() == newHeight) {
      break;
    } else {
      temp->setHeight(newHeight);
    }
  }

  // Perform rotations to balance the tree
  if (unbalanced) {
    current = temp;
    
    if (nodesTraverse.empty()) {
      previous = nullptr;
    } else {
      previous = nodesTraverse.back();
    }

    if (newNode->getData() < current->getData()) {
      // Case 1 or 2
      Node<T> *L = current->getLeft();

      if (newNode->getData() > L->getData()) {
        // Case 2
        current->setLeft( L->leftRotate() );
      }

      // Cases 1 and 2
      if (previous == nullptr) {
        root = current->rightRotate();
      } else if (previous->getLeft() == current) {
        previous->setLeft( current->rightRotate() );
      } else {
        previous->setRight( current->rightRotate() );
      }
    } else {
      // Case 3 or 4
      Node<T> *R = current->getRight();

      if (newNode->getData() < R->getData()) {
        // Case 3
        current->setRight( R->rightRotate() );
      }

      // Cases 3 and 4
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

// TODO
template<typename T> 
void AVL<T>::remove(T item)
{
}

template class AVL<int>;
template class AVL<float>;
template class AVL<double>;
template class AVL<std::string>;
