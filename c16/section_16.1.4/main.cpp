#include <bits/stdc++.h>
#include "TextQuery.h"
#include "Blob.h"

using namespace std;

template < typename Container >
void print_container (Container container)
  {
    for (auto &item : container)
      {
        cout << item << " ";
      }
    cout << endl;
  }

int main ()
try
  {
//    auto s_ptr { new int };
//    cout << *s_ptr << endl;
//
//    DebugDelete debug_delete;
//    debug_delete(s_ptr);
////    DebugDelete()(s_ptr);
//
//    unique_ptr<string, DebugDelete> up { new string { "up string..." }, DebugDelete() };
//
//    cout << *up << endl;
//
//    ifstream ifs { "../text.txt" };
//    runQueries(ifs);

    vector<int> v1 { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> v2 { v1.begin() + 3, v1.end() };
    vector<string> v3 { "A", "B", "C", "D", "E" };

    print_container(v1);
    print_container(v2);

    Blob<string> blob_string { v3.begin() + 2, v3.end() - 1 };
    Blob<int> blob_int { v1.begin() + 3, v1.end() };

    cout << "-----------------" << endl;

    cout << blob_int << endl;
    cout << blob_string << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


