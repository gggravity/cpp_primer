#pragma once
//
// Created by martin on 26/05/2022.
//

#include <bits/stdc++.h>
#include <ostream>
#include "tree_node.h"

using namespace std;

struct bin_str_tree
   {
      explicit bin_str_tree (tree_node *root);

      friend ostream &operator<< (ostream &os, const bin_str_tree &tree);

   private:
      tree_node *root;
   };
