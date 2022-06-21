#pragma once
//
// Created by martin on 26/05/2022.
//

#include "tree_node.h"
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct bin_str_tree
{
  bin_str_tree() = default;

  explicit bin_str_tree (tree_node *root);

  bin_str_tree (const bin_str_tree &node);

  bin_str_tree &operator= (const bin_str_tree &node);

  virtual ~bin_str_tree();

  friend ostream &operator<< (ostream &os, const bin_str_tree &tree);

private:

  tree_node *root;
};
