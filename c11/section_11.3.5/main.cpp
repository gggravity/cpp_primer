#include <bits/stdc++.h>

using namespace std;

void print (const multimap<string, string> &authors)
{
  multimap<string, string> print_map;

  for (auto &author : authors)
    {
      print_map.insert ({author.second, author.first});
    }

  for (auto &p : print_map)
    {
      cout << p.second << ": " << p.first << endl;
    }
}

int main()
try
  {
    // e 11.28

    //    map<string, vector<int>> m;
    //
    //    for (int i { 0 } ; i < 10 ; ++i)
    //      {
    //        m["element" + to_string(i)];
    //        for (int j { 0 } ; j < 10 ; ++j)
    //          {
    //            m["element" + to_string(i)].push_back(rand() % 10);
    //          }
    //      }
    //
    //    for (auto &item : m)
    //      {
    //        cout << item.first << ": ";
    //        for (auto &i : item.second)
    //          {
    //            cout << i << " ";
    //          }
    //        cout << endl;
    //      }
    //
    //    map<string, vector<int>>::const_iterator iter = m.find("element3");
    //    cout << iter->first << endl;
    //    for (auto &i : iter->second)
    //      {
    //        cout << i << " ";
    //      }

    // e 11.29
    //    multimap<int, int> m;
    //
    //    for (int i { 0 } ; i < 10 ; ++i)
    //      {
    //        m.insert({ i, i });
    //        m.insert({ i, i });
    //        m.insert({ i, i });
    //      }
    //
    //    cout << boolalpha;
    //
    //    cout << "lower_bound not found" << endl;
    //    cout << ( m.lower_bound(11) == m.end() ) << endl;
    //
    //    cout << "upper_bound not found" << endl;
    //    cout << ( m.upper_bound(11) == m.end() ) << endl;
    //
    //    cout << "equal_range not found" << endl;
    //    cout << ( m.equal_range(11).first == m.end() ) << endl;
    //
    //    // e 11.30
    //    // first value in the pair and then the second value in that pair.

    // e 11.31
    multimap<string, string> authors;
    authors.insert ({"Barth, John", "Sot-Weed Factor"});
    authors.insert ({"Barth, John", "Lost in the Funhouse"});
    authors.insert ({"John, John", "A Space work purple"});

    //    for (auto &author : authors)
    //      {
    //        cout << author.first << ": " << author.second << endl;
    //      }
    string name {"John John"};
    auto found = authors.find (name);
    if (found != authors.end())
      {
        cout << "Deleting " << name << endl;
        authors.erase (found);
      }
    else
      {
        cerr << "404 Author Not Found" << endl;
      }

    //    for (auto &author : authors)
    //      {
    //        cout << author.first << ": " << author.second << endl;
    //      }

    // e 11.32
    print (authors);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
