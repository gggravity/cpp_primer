#include <bits/stdc++.h>
#include "has_ptr.h"
#include "tree_node.h"
#include "bin_str_tree.h"

using namespace std;

int main ()
try
  {

//    has_ptr h1 { "some string" };
//    has_ptr h2 { h1 };
//    has_ptr h3;
//    h3 = h1;
//
//    cout << h1 << endl;
//    cout << h2 << endl;
//    cout << h3 << endl;
//
//    cout << "-------------" << endl;

    tree_node node1 { "node 1", 100, nullptr, nullptr };
    tree_node node2 { "node 2", 200, nullptr, nullptr };

    bin_str_tree str_node1 { &node1 };
    bin_str_tree str_node2 { &node2 };

    cout << node1 << endl;
    cout << node2 << endl;

    cout << str_node1 << endl;
    cout << str_node2 << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
