//
// Created by martin on 26/05/2022.
//

#include "bin_str_tree.h"
#include "tree_node.h"

bin_str_tree::bin_str_tree (tree_node *root) : root (root) { root->count++; }

bin_str_tree::bin_str_tree (const bin_str_tree &node)
{
  cout << "calling copy constructor" << endl;
  root = node.root;
}

bin_str_tree &bin_str_tree::operator= (const bin_str_tree &node)
{
  cout << "calling copy assignment operator" << endl;

  if (this == &node)
    {
      return *this;
    }

  root = node.root;

  return *this;
}

ostream &operator<< (ostream &os, const bin_str_tree &tree)
{
  os << "root: " << tree.root->value;
  return os;
}

bin_str_tree::~bin_str_tree()
{
  if (root->count == 0)
    {
      delete root;
    }
  cout << "deleting tree..." << endl;
}
