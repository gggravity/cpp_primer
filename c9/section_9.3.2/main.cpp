#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    // e 9.23

    list<int> c {1};

    if (! c.empty())
      {
        auto val = *c.begin(), val2 = c.front();

        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();

        cout << "val: " << val << endl;
        cout << "val2: " << val2 << endl;
        cout << "val3: " << val3 << endl;
        cout << "val4: " << val4 << endl;
      }

    // e 9.24

    vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2;

    cout << v1.at (0) << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;

    cout << v2.at (0) << endl;
    cout << v2.front() << endl;
    cout << v2.back() << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
