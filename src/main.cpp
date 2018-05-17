#include <iostream>

#include "avl.h"
#include "node.h"
#include "util.h"

int main()
{
  AVL<int> test;
  test.add(5);
  test.print();

  //std::cout << "x: " << x->getData() << std::endl;

  return 0;
}
