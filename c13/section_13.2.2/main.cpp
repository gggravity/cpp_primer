#include "bin_str_tree.h"
#include "has_ptr.h"
#include "tree_node.h"
#include <bits/stdc++.h>

using namespace std;

int main()
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

    // destructor test
    //    auto node1left = new tree_node { "node1left", 0, nullptr, nullptr };
    //    auto node1right = new tree_node { "node1right", 0, nullptr, nullptr };
    //    auto node2left = new tree_node { "node2left ", 0, nullptr, nullptr };
    //    auto node2right = new tree_node { "node2right", 0, nullptr, nullptr };
    //
    //    auto root1 = new tree_node { "node 1", 1, node1left, node1right };
    //////    delete root1;
    ////
    //    auto root2 = new tree_node { "node 2", 1, node2left, node2right };
    ////    delete root2;

    //    bin_str_tree str_node1 { root1 };
    //    bin_str_tree str_node2 { root2 };

    //    auto node1 = new tree_node();
    //    auto node2 = new tree_node(*root1);
    //    cout << "-----" << endl;
    //    tree_node t1;
    //    tree_node t2 { "t1", 1, node1left, node1right };
    //    t1 = t2;
    //    node1 = root1; // assignment operator are not used with points?
    //    cout << "-----" << endl;
    //
    //    cout << "node1: " << *node1 << endl;
    //    cout << "node2: " << *node2 << endl;
    //    cout << "root1: " << *root1 << endl;

    tree_node node {"test node", 0, nullptr, nullptr};
    bin_str_tree bst1 {&node};
    //    bin_str_tree bst2(bst1);
    //    bin_str_tree bst3;

    //    bst3 = bst1;

    //    cout << bst1 << endl;
    //    cout << bst2 << endl;
    //    cout << bst3 << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
