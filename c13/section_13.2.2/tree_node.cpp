//
// Created by martin on 26/05/2022.
//

#include "tree_node.h"

tree_node::tree_node (string value, int count, tree_node *left, tree_node *right) :
    value(value),
    count(count),
    left(left),
    right(right)
  {

  }

ostream &operator<< (ostream &os, const tree_node &node)
  {
    os << "value: " << node.value << " count: " << node.count << " left: " << node.left << " right: " << node.right;
    return os;
  }
