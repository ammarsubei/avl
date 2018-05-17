/**
 *  @brief Node class definitions
 *
 *  @author Ammar Subei
 */

#include <string>

#include "node.h"
#include "util.h"

template<typename T>
Node<T>* Node<T>::rightRotate()
{
  // Get the necessary nodes
  Node<T> *t = this->left;
  Node<T> *b = t->right;

  // Rotate target T up, and source (this) down right
  t->right = this;
  this->left = b;

  // Now adjust heights
  this->setHeight( 1 + max( (this->left->getHeight()), (this->right->getHeight()) ) ); 
  t->setHeight( 1 + max( (t->left->getHeight()), (t->right->getHeight()) ) ); 

  // Return new root of subtree
  return t;
}

template<typename T>
Node<T>* Node<T>::leftRotate()
{
  // Get the necessary nodes
  Node<T> *t = this->right;
  Node<T> *b = t->left;

  // Rotate target t up, and source (this) down left
  t->left = this;
  this->right = b;

  // Now adjust heights
  this->setHeight( 1 + max( (this->left->getHeight()), (this->right->getHeight()) ) ); 
  t->setHeight( 1 + max( (t->left->getHeight()), (t->right->getHeight()) ) ); 

  // Return new root of subtree
  return t;
}

template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<std::string>;
