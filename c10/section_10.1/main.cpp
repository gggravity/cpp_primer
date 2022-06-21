#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    vector<int> vi {1, 1, 2, 5, 4, 5, 6, 7, 5, 8};

    for (int i {0}; i < 10; ++i)
      {
        cout << "count(" << i << "): " << count (vi.cbegin(), vi.cend(), i) << endl;
      }

    cout << "-----------" << endl;

    list<int> li {1, 1, 2, 5, 4, 5, 6, 7, 5, 8};

    for (int i {0}; i < 10; ++i)
      {
        cout << "count(" << i << "): " << count (li.cbegin(), li.cend(), i) << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
