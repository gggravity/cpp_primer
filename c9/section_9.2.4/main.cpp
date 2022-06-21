#include <bits/stdc++.h>

using namespace std;

void print (const vector<int> &vec, const string &name)
{
  cout << name << ": ";
  for (auto &v : vec)
    {
      cout << setw (2) << v << " ";
    }
  cout << endl;
}

void print (const vector<double> &vec, const string &name)
{
  cout << name << ": ";
  for (auto &v : vec)
    {
      cout << setw (2) << v << " ";
    }
  cout << endl;
}

void print (const deque<int> &deq, const string &name)
{
  cout << name << ": ";
  for (auto &d : deq)
    {
      cout << setw (2) << d << " ";
    }
  cout << endl;
}

int main (int argc, char *argv[])
try
  {
    vector<int> v1;
    vector<int> v2 (10);
    vector<int> v3 (10, 10);
    vector<int> v4 {v3};
    vector<int> v5 {v4.begin(), v4.end()};
    vector<int> v6 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    print (v1, "v1");
    print (v2, "v2");
    print (v3, "v3");
    print (v4, "v4");
    print (v5, "v5");
    print (v6, "v6");

    // e 9.12
    //    deque<int> d1 = v6; // don't work, need to be same type and same container.
    deque<int> d2 {v6.begin(), v6.end()};

    cout << "--------------------" << endl;

    print (d2, "d2");

    // e 9.13

    list<int> li {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<double> vd1 {li.begin(), li.end()};
    vector<double> vd2 {vi.begin(), vi.end()};

    cout << "--------------------" << endl;

    print (vd1, "vd1");
    print (vd2, "vd2");

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
