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
    bitset<64> bit_vector (32);
    bitset<32> bv (1010101);

    print (bit_vector);
    print (bv);
    print (bitset<13> (0xbeef));
    print (bitset<20> (0xbeef));
    print (bitset<128> (~0ULL));

    string bit_string;
    istringstream iss {"101"};

    iss >> bit_string;

    //    print(bitset<8>("Hello World!!!")); // Error: bitset::_M_copy_from_ptr

    print (bitset<8> (bit_string));

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
