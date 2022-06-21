#pragma once
//
// Created by martin on 26/05/2022.
//

#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct tree_node
{
  tree_node() = default;

  tree_node (string value, int count, tree_node *left, tree_node *right);

  virtual ~tree_node();

  tree_node (const tree_node &node);

  tree_node &operator= (const tree_node &node);

  string value;
  int count {};

  friend ostream &operator<< (ostream &os, const tree_node &node);

private:

  tree_node *left {};
  tree_node *right {};
};