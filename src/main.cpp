#include <iostream>

#include "avl.h"
#include "node.h"
#include "util.h"

int main()
{
  AVL<int> test;
  test.add(5);
  test.add(3);
  test.add(2);
  test.add(4);
  test.add(6);
  test.print();

  std::cout << "tree height: " << test.getHeight() << std::endl;

  return 0;
}
