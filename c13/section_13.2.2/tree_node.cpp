//
// Created by martin on 26/05/2022.
//

#include "tree_node.h"

tree_node::tree_node (string value, int count, tree_node *left, tree_node *right) :
    value(move(value)),
    count(count),
    left(left),
    right(right)
  {

  }

tree_node::tree_node (const tree_node &node)
  {
    cout << "calling copy constructor" << endl;
    value = node.value;
    count = node.count;
    left = node.left;
    right = node.right;
  }

tree_node &tree_node::operator= (const tree_node &node)
  {
    cout << "calling copy assignment operator" << endl;
    if (this == &node)
      {
        return *this;
      }

    value = node.value;
    count = node.count;
    left = node.left;
    right = node.right;

    return *this;
  }

ostream &operator<< (ostream &os, const tree_node &node)
  {
    os << "value: " << node.value
       << " count: " << node.count
       << " left: " << node.left->value
       << " right: " << node.right->value;
    return os;
  }

tree_node::~tree_node ()
  {
    delete left;
    delete right;
    --count;

    cout << "node: " << value << " destroyed" << endl;
  }






