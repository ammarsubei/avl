/**
 *  @brief Node class definitions
 *
 *  @author Ammar Subei
 */

#include <cmath>
#include <string>
#include <iostream>

#include "node.h"
#include "util.h"

template<typename T>
Node<T>::~Node()
{
  if (left) delete left;
  if (right) delete right;
}

template<typename T>
bool Node<T>::updateHeight()
{
  // Tree balanced by default
  bool balanced = true;

  // Height of -1 represent nonexistent node
  int heightLeft = -1;
  int heightRight = -1;

  // If child nodes exist, get their heights
  if (getLeft()) {
    heightLeft = getLeft()->getHeight();
  }

  if (getRight()) {
    heightRight = getRight()->getHeight();
  }

  const int newHeight = 1 + max(heightLeft, heightRight);

  if ( std::abs(heightLeft - heightRight) > 1 ) {
    balanced = false;
  } else if (getHeight() != newHeight) {
    setHeight(newHeight);
  }

  return balanced;
}

template<typename T>
Node<T>* Node<T>::rightRotate()
{
  // Get the necessary nodes
  Node<T> *t = getLeft();
  Node<T> *b = t->getRight();

  // Rotate target T up, and source (this) down right
  t->setRight(this);
  setLeft(b);

  // Now adjust heights
  updateHeight();
  t->updateHeight();

  // Return new root of subtree
  return t;
}

template<typename T>
Node<T>* Node<T>::leftRotate()
{
  // Get the necessary nodes
  Node<T> *t = getRight();
  Node<T> *b = t->getLeft();

  // Rotate target t up, and source (this) down left
  t->setLeft(this);
  setRight(b);

  // Now adjust heights
  updateHeight();
  t->updateHeight();

  // Return new root of subtree
  return t;
}

template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<std::string>;
