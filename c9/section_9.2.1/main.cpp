#include <bits/stdc++.h>

using namespace std;

bool find_in_vector (int value_to_find, vector<int>::iterator begin, vector<int>::iterator end)
  {
    while (begin != end)
      {
        if (*begin == value_to_find)
          {
            return true;
          }
        begin++;
      }
    return false;
  }

vector<int>::iterator find_in_vector_v2 (int value_to_find, vector<int>::iterator begin, vector<int>::iterator end)
  {
    while (begin != end)
      {
        if (*begin == value_to_find)
          {
            return begin;
          }
        begin++;
      }
    return end;
  }

int main (int argc, char *argv[])
try
  {
    vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << boolalpha;

    cout << find_in_vector(0, vec.begin(), vec.end()) << endl;
    cout << find_in_vector(9, vec.begin(), vec.end()) << endl;

    cout << "-----------------" << endl;

    auto iter_1 = find_in_vector_v2(0, vec.begin(), vec.end());
    auto iter_2 = find_in_vector_v2(9, vec.begin(), vec.end());

    if (iter_1 != vec.end())
      {
        cout << *iter_1 << endl;
      }
    else
      {
        cout << "Not found" << endl;
      }

    if (iter_2 != vec.end())
      {
        cout << *iter_2 << endl;
      }
    else
      {
        cout << "Not found" << endl;
      }

    cout << "-----------------" << endl;

    list<int> lst1 { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto iter1 = lst1.begin();
    auto iter2 = lst1.end();

    while (iter1 != iter2)
      {
        cout << *iter1++ << " ";
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }














