#include <bits/stdc++.h>
#include "SalesData.hpp"

using namespace std;

typedef vector<SalesData> vsd;
typedef pair<vsd::size_type, pair<vsd::const_iterator, vsd::const_iterator>> matches;
typedef vector<vsd> Files;

struct Comp
    {
        bool operator() (const SalesData &s, string i) const
          { return s.isbn() < i; }

        bool operator() (string i, const SalesData &s) const
          { return i < s.isbn(); }
    };

auto find_book (const vector<vector<SalesData>> &files, const string &book)
  {
    vector<matches> ret;

    for (auto it { files.cbegin() } ; it != files.cend() ; ++it)
      {
        auto found = equal_range(
            it->cbegin(),
            it->cend(),
            book,
            compare_ISBN
        );

        if (found.first != found.second)
          {
            ret.push_back(make_pair(it - files.cbegin() + 1,
                                    make_pair(found.first, found.second)));
          }
      }
    return ret;
  }

auto report_results (istream &is, ostream &os, Files files)
  {
    string s;
    while (is >> s)
      {
        auto trans { find_book(files, s) };

        if (trans.empty())
          {
            cout << s << " not found in any stores" << endl;
            continue;
          }
        for (const auto &store : trans)
          {
            os << "store " << store.first << " sales: "
               << accumulate(store.second.first,
                             store.second.second,
                             SalesData(s))
               << endl;
          }
      }
  }

int main ()
try
  {
    vector<SalesData> store1;
    store1.emplace_back("111", 1, 9.98);
    store1.emplace_back("222", 1, 9.98);
    store1.emplace_back("222", 1, 9.98);
    store1.emplace_back("222", 1, 9.98);
    store1.emplace_back("333", 1, 9.98);

    vector<SalesData> store2;
    store2.emplace_back("222", 1, 9.98);
    store2.emplace_back("333", 1, 9.98);
    store2.emplace_back("444", 1, 9.98);

    vector<SalesData> store3;
    store3.emplace_back("111", 1, 9.98);
    store3.emplace_back("222", 1, 9.98);
    store3.emplace_back("333", 1, 9.98);

    vector<SalesData> store4;
    store4.emplace_back("222", 1, 9.98);
    store4.emplace_back("333", 1, 9.98);
    store4.emplace_back("444", 1, 9.98);

    Files files { store1, store2, store3, store4 };

    istringstream iss { "222" };

    report_results(iss, cout, files);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


