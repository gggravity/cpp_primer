#include "SalesData.hpp"
#include <bits/stdc++.h>

using namespace std;

template <typename Container, typename Value> auto count_occurrences (Container container, Value value)
{
  size_t counter {0};

  for (auto &i : container)
    {
      if (i == value)
        {
          counter++;
        }
    }
  return counter;
}

template <> auto count_occurrences (vector<const char *> container, const char *value)
{
  cout << "I am special..." << endl;

  size_t counter {0};

  for (auto &i : container)
    {
      if (i == value)
        {
          counter++;
        }
    }
  return counter;
}

int main()
try
  {
    SalesData sd1 {"123-XXX", 10, 9.98};
    SalesData sd2 {"123-XXX", 10, 9.98};

    unordered_multiset<SalesData> sales_set;

    sales_set.emplace ("123-XXX", 1, 9.98);
    sales_set.emplace ("123-XXX", 4, 9.98);
    sales_set.emplace ("123-XXX", 10, 9.98);
    sales_set.emplace ("123-YYY", 7, 7.98);
    sales_set.emplace ("123-YYY", 3, 7.98);
    sales_set.emplace ("123-QWE", 1, 5.00);
    sales_set.emplace ("123-XYZ", 1, 18.50);

    for (auto &i : sales_set)
      {
        cout << i << endl;
      }

    vector<int> v1 {1, 1, 1, 1, 3, 4, 5, 6, 7, 8, 9};
    vector<double> v2 {1.1, 1.1, 1.0, 1.1, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    vector<string> v3 {"1", "1", "1", "1", "3", "4", "5", "6", "7", "8", "9"};
    vector<const char *> v4 {"1", "1", "1", "1", "3", "4", "5", "6", "7", "8", "9"};

    cout << count_occurrences (v1, 1) << endl;
    cout << count_occurrences (v2, 1.1) << endl;
    cout << count_occurrences (v3, "1") << endl;
    cout << count_occurrences (v4, "1") << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
