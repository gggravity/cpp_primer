#include <bits/stdc++.h>

using namespace std;

int main ()
try
  {
    // e 11.24

    map<int, int> m;

    m[0] = 1;

    for (auto &item : m)
      {
        cout << item.first << " " << item.second << endl;
      }

    // e 11.25

//    array<int, 10> v;
    vector<int> v;
    v.push_back(1);
//    v[0] = 1;

    for (int i { 0 } ; i < v.size() ; ++i)
      {
        cout << i << " " << v[i] << endl;
      }

    // e 11.26

    map<int, int> int_int_map;

    auto count = int_int_map[1] = 4;

    if (count)
      {
        cout << "value exist" << endl;
      }
    else
      {
        cout << "value don't exist" << endl;
      }

    count = int_int_map[1];
    if (count)
      {
        cout << "value exist" << endl;
      }
    else
      {
        cout << "value don't exist" << endl;
      }

    count = int_int_map[2];
    if (count)
      {
        cout << "value exist" << endl;
      }
    else
      {
        cout << "value don't exist" << endl;
      }

    for (auto &i : int_int_map)
      {
        cout << i.first << " " << i.second << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


