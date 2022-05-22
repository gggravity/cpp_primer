#include <bits/stdc++.h>
#include "Sales_data.h"

using namespace std;

bool is_punctuation (char c)
  {
    return c == '.' || c == ',';
  }

int main ()
try
  {
    // e 11.9

//    map<string, vector<int>> line_number_map;
//
//    ifstream ifs { "../text.txt" };
//
//    if (!ifs)
//      {
//        cerr << "Error opening file." << endl;
//        exit(EXIT_FAILURE);
//      }
//
//    for (string line ; getline(ifs, line) ;)
//      {
//        static int line_no { 1 };
//        istringstream iss { line };
//        for (string word ; iss >> word ;)
//          {
//            word.erase(remove_if(word.begin(), word.end(), is_punctuation), word.end());
//
//            transform(word.begin(), word.end(), word.begin(), [] (unsigned char c)
//              {
//                  return std::tolower(c);
//              });
//
//            line_number_map[word].push_back(line_no);
//          }
//        ++line_no;
//      }
//
//    for (auto &word : line_number_map)
//      {
//        cout << word.first << ": ";
//        for (auto &i : word.second)
//          {
//            cout << i << " ";
//          }
//        cout << endl;
//      }

    vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    map<vector<int>::iterator, int> test_vector_map;

    for (int i {0}; i < 5; ++i)
      {
        test_vector_map[vi.begin() + i ] = i;
      }

    for (auto &item : test_vector_map)
      {
        cout << "first: " << *item.first << ", second: " << item.second << endl;
      }

//    list<int> li { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//    map<list<int>::iterator, int> test_list_map;
//
//    for (int i {0}; i < 5; ++i)
//      {
//        test_list_map[li.begin() + i] = i; // ERROR less than required.
//      }
//
//    for (auto &item : test_list_map)
//      {
//        cout << "first: " << *item.first << ", second: " << item.second << endl;
//      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


