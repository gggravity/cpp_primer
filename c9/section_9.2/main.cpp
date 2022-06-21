#include <bits/stdc++.h>

using namespace std;

void print (const deque<int> &deque)
{
  for (auto &d : deque)
    {
      cout << d << " ";
    }
  cout << endl;
}

int main (int argc, char *argv[])
try
  {
    list<deque<int>> deque_list;

    deque d1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque d2 {9, 8, 7, 6, 5, 4, 3, 2, 1};

    deque_list.push_back (d1);
    deque_list.push_back (d2);

    for (auto &d : deque_list)
      {
        print (d);
      }

    swap (deque_list.front(), deque_list.back());

    cout << "---------------------------" << endl;

    for (auto &d : deque_list)
      {
        print (d);
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
