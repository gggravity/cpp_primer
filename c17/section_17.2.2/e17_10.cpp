#include <bits/stdc++.h>

using namespace std;

template <typename Bitset> void print (Bitset bitset)
{
  for (size_t i {0}; i < bitset.size(); ++i)
    {
      cout << bitset[i];
    }
  cout << endl;
}

int main()
try
  {
    string bit_string {"0111010010000100000001"};
    reverse (bit_string.begin(), bit_string.end());
    bitset<22> bitset1 {bit_string};

    print (bitset1);

    vector<int> v {1, 2, 3, 5, 8, 13, 21};
    bitset<22> bitset2;

    for (auto &i : v)
      {
        bitset2.set (i);
      }

    print (bitset2);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
