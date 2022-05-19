#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {

    // e 9.18
//    deque<string> deq;
//    for (string input ; cin >> input && input != "Q" ;)
//      {
//        deq.push_back(input);
//      }
//
//    for (auto it { deq.cbegin() } ; it != deq.cend() ; ++it)
//      {
//        cout << *it << endl;
//      }

    // e 9.19
//    list<string> string_list;
//    for (string input ; cin >> input && input != "Q" ;)
//      {
//        string_list.push_back(input);
//      }
//
//    for (auto it { string_list.cbegin() } ; it != string_list.cend() ; ++it)
//      {
//        cout << *it << endl;
//      }
//
    // e 9.20

//    list<int> il { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//    deque<int> odds;
//    deque<int> evens;
//
//    for (auto &i : il)
//      {
//        if (i % 2 == 0)
//          {
//            evens.push_back(i);
//          }
//        else
//          {
//            odds.push_back(i);
//          }
//      }
//
//    cout << "odds: ";
//    for (auto &odd : odds)
//      {
//        cout << odd << " ";
//      }
//    cout << endl;
//
//    cout << "evens: ";
//    for (auto &even : evens)
//      {
//        cout << even << " ";
//      }
//    cout << endl;

    // e.21

//    istringstream iss1 { "der var en gang en mand" };
//    string word1;
//
//    list<string> lst1;
//    auto iter1 = lst1.begin();
//    while (iss1 >> word1)
//      {
//        iter1 = lst1.insert(iter1, word1);
//      }
//
//    for (auto &item : lst1)
//      {
//        cout << item << " ";
//      }
//
//    cout << endl;
//
//    istringstream iss2 { "der var en gang en mand" };
//    string word2;
//
//    vector<string> lst2;
//    auto iter2 = lst2.begin();
//    while (iss2 >> word2)
//      {
//        iter2 = lst2.insert(iter2, word2);
//      }
//
//    for (auto &item : lst2)
//      {
//        cout << item << " ";
//      }
//
//      // they are the same, but vector have to move all the elements.
//
//

    // e 9.22

    int some_val { 1 };
    vector<int> iv { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto iter = iv.begin();
    auto mid = iv.begin() + iv.size() / 2;

    while (iter != mid)
      {
        if (*iter == some_val)
          {
            iv.insert(iter, 2 * some_val);
          }
        iter++; // need to move to next element.
      }

    for (auto &i : iv)
      {
        cout << i << " ";
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }














