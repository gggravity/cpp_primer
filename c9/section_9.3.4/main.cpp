#include <bits/stdc++.h>

using namespace std;

forward_list<string> &find_and_replace (forward_list<string> &list, const string &find, const string &replace)
  {
    bool found = false;
    auto previous = list.before_begin();
    auto iterator = list.begin();

    while (iterator != list.end())
      {
        if (*iterator == find)
          {
            iterator = list.insert_after(iterator, replace);
            found = true;
          }
        else
          {
            ++iterator;
          }
          ++previous;
      }
    if (!found)
      {
        list.insert_after(previous, replace);
      }

    return list;
  }

int main (int argc, char *argv[])
try
  {
/*
    forward_list<int> f_list { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    for (auto &i : f_list)
      {
        cout << i << " ";
      }
    cout << endl;

    cout << "----------------------------" << endl;

    auto previous = f_list.before_begin();
    auto current = f_list.begin();

    while (current != f_list.end())
      {
        if (*current % 2)
          {
            current = f_list.erase_after(previous);
          }
        else
          {
            previous = current;
            ++current;
          }
      }

    for (auto &i : f_list)
      {
        cout << i << " ";
      }
    cout << endl;

    cout << "-----------------------" << endl;
*/
    forward_list<string> f_list_s { "anna", "john", "frank", "kris" };

    f_list_s = find_and_replace(f_list_s, "johhh", "smith");

    for (auto &i : f_list_s)
      {
        cout << i << " ";
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }














