#include <bits/stdc++.h>

using namespace std;

int main ()
try
  {
    // e 11.16
    map<string, int> m;

    for (int i { 0 } ; i < 10 ; ++i)
      {
        m.insert({ "element" + to_string(i), i });
      }

    for (auto iter = m.begin() ; iter != m.end() ; ++iter)
      {
        iter->second = rand() % 100;
      }

    for (auto &pair : m)
      {
        cout << pair.first << " -> " << pair.second << endl;
      }

    // e 11.17
    multiset<string> c { "1", "2", "3" };
    vector<string> v; // { "1", "1", "2", "3", "3", "4", "5", "6", "7", "8", "8", "8", "9" };
//    copy(v.begin(), v.end(), inserter(c, c.end())); // copy v to c
//    for (auto &item : c)
//      {
//        cout << item << " ";
//      }
//    cout << endl;

//    copy(v.begin(), v.end(), back_inserter(c)); // set are not ordered and don't have push_back

//    copy(c.begin(), c.end(), inserter(v, v.end())); // copy c to v
//    for (auto &item : v)
//      {
//        cout << item << " ";
//      }
//    cout << endl;

    copy(c.begin(), c.end(), back_inserter(v)); // copy c to v
    for (auto &item : v)
      {
        cout << item << " ";
      }
    cout << endl;

    // e 11.18

    map<string, size_t> word_count;

//    auto map_it { word_count.cbegin() };

    map<string, size_t>::const_iterator map_it { word_count.cbegin() };

    // e 11.19

    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &>::iterator it = bookstore.begin();

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


