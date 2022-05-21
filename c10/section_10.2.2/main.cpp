#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    // e 10.6
    vector<int> v;
    fill_n(back_inserter(v), 6, 6);

    for (auto &i : v)
      {
        cout << i << " ";
      }

    cout << endl;

    // e 10.7
    vector<int> vec;
    list<int> lst;
    int i;

    istringstream iss { "1 2 3 4 5 6 7 8 9" };

    while (iss >> i)
      {
        lst.push_back(i);
      }
    copy(lst.cbegin(), lst.cend(), back_inserter(vec)); // need back_inserter

    cout << "lst: ";
    for (auto item : lst)
      {
        cout << item << " ";
      }
    cout << endl;

    cout << "vec: ";
    for (auto item : vec)
      {
        cout << item << " ";
      }
    cout << endl;


    vector<int> vec_int;
    vec_int.reserve(10);
    fill_n(back_inserter(vec_int), 10, 0); // need back_inserter

    cout << "vec_int: ";
    for (auto item : vec_int)
      {
        cout << item << " ";
      }
    cout << endl;

    // e 10.8
    // back_inserter change the container not the algorithm.


    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


