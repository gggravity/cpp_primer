#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {

    // e 9.25
//    vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//    auto elem1 = v.end();
//    auto elem2 = v.end();
//
//    elem1 = v.erase(elem1, elem2);
//
//    for (auto &i : v)
//      {
//        cout << i << " ";
//      }

    // e 9.26

    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    vector<int> ia_vector { begin(ia), end(ia) };
    list<int> ia_list { begin(ia), end(ia) };

    for (auto &i : ia_vector)
      {
        cout << i << " ";
      }
    cout << endl;

    cout << "----------------------------" << endl;

    for (auto it = ia_vector.begin() ; it != ia_vector.end() ;)
      {
        if (*it % 2)
          {
            ia_vector.erase(it);
          }
        else
          {
            ++it;
          }
      }

    for (auto &i : ia_vector)
      {
        cout << i << " ";
      }
    cout << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }














