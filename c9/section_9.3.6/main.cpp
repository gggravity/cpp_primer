#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    //
    //    // e 9.31
    //
    //    vector<int> vi { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //    auto iter1 { vi.begin() };
    //    while (iter1 != vi.end())
    //      {
    //        if (*iter1 % 2)
    //          {
    //            iter1 = vi.insert(iter1, *iter1);
    //            iter1 += 2;
    //          }
    //        else
    //          {
    //            iter1 = vi.erase(iter1);
    //          }
    //      }
    //
    //    for (auto &i : vi)
    //      {
    //        cout << i << " ";
    //      }
    //
    //    cout << endl << "------------------------------" << endl;
    //
    //    list<int> li { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //    auto iter2 { li.begin() };
    //    while (iter2 != li.end())
    //      {
    //        if (*iter2 % 2)
    //          {
    //            iter2 = li.insert(iter2, *iter2);
    //            advance(iter2, 2);
    //          }
    //        else
    //          {
    //            iter2 = li.erase(iter2);
    //          }
    //      }
    //
    //    for (auto &i : li)
    //      {
    //        cout << i << " ";
    //      }
    //
    //    cout << endl << "------------------------------" << endl;
    //
    //    forward_list<int> fli { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //    auto current { fli.begin() };
    //    auto prev { fli.before_begin() };
    //
    //    while (current != fli.end())
    //      {
    //        if (*current % 2)
    //          {
    //            prev = fli.insert_after(prev, *current);
    //            prev++;
    //            current++;
    //          }
    //        else
    //          {
    //            current = fli.erase_after(prev);
    //          }
    //      }
    //
    //    for (auto &i : fli)
    //      {
    //        cout << i << " ";
    //      }
    //
    //    // e 9.32 - yes.
    //
    //    cout << endl << "------------------------------" << endl;
    //
    //    // e 9.33
    //
    //    vector<int> v { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //
    //    auto begin = v.begin();
    //
    //    while (begin != v.end())
    //      {
    //        ++begin;
    //        begin = v.insert(begin, 42); // need to assign, insert invalidate begin.
    //        ++begin;
    //      }
    //
    //    for (auto &i : v)
    //      {
    //        cout << i << " ";
    //      }
    //
    //    // e. 9.34
    //
    //    cout << endl << "------------------------------" << endl;

    vector<int> vi {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : vi)
      {
        cout << i << " ";
      }

    auto iter = vi.begin();

    while (iter != vi.end())
      {
        if (*iter % 2)
          {
            iter = vi.insert (++iter, *iter);  // should advance before inserting, or inf loop.
          }
        ++iter;
      }

    cout << endl;

    for (auto &i : vi)
      {
        cout << i << " ";
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
