#include <bits/stdc++.h>
#include "SalesData.hpp"

using namespace std;

void greater (const vector<SalesData> &vs, double N)
  {
    auto ret = find_if(vs.begin(), vs.end(), [N] (const SalesData &sd)
      {
          return sd.avg_price() > N;
      });

    if (ret != vs.end())
      {
        cout << ret->isbn() << " priced at " << ret->avg_price() << " is more expensive then " << N << "." << endl;
      }
    else
      {
        cout << "No books more expensive then " << N << "." << endl;
      }
  }

int main ()
  {

    vector<string> v { "A", "B", "C", "", "", "D", "E", "D", "", "X" };

    auto count { count_if(v.begin(), v.end(), mem_fn(&string::empty)) };

    cout << "count: " << count << endl;

    vector<SalesData> vs { { "10-XXX", 1, 10 },
                           { "20-XXX", 1, 20 },
                           { "30-XXX", 1, 30 },
                           { "10-XXX", 1, 10 },
                           { "40-XXX", 1, 40 },
                           { "20-XXX", 1, 20 } };

    ::greater(vs, 10);
    ::greater(vs, 20);
    ::greater(vs, 30);
    ::greater(vs, 40);
    ::greater(vs, 50);

    return 0;
  }
