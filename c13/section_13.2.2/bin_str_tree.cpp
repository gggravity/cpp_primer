//
// Created by martin on 26/05/2022.
//

#include "bin_str_tree.h"
#include "tree_node.h"

bin_str_tree::bin_str_tree (tree_node *root) :
    root(root)
  {

  }

ostream &operator<< (ostream &os, const bin_str_tree &tree)
  {
    os << "root: " << tree.root->value;
    return os;
  }
