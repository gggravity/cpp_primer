#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it {vi.crbegin()}; it != vi.crend(); ++it)
      {
        cout << *it << " ";
      }

    cout << endl << "-----------" << endl;

    for (auto it {vi.cend() - 1}; it != vi.cbegin() - 1; --it)
      {
        cout << *it << " ";
      }

    cout << endl << "-----------" << endl;
    list<int> i_list {1, 2, 3, 0, 5, 6, 0, 8, 9};

    auto iter = find (i_list.crbegin(), i_list.crend(), 0);
    cout << distance (i_list.crbegin(), iter) << " " << *iter << endl;

    cout << "-----------" << endl;
    vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l;
    copy (v.crbegin(), v.crbegin() + 7, back_inserter (l));
    for (auto &item : l)
      {
        cout << item << " ";
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
