#include <bits/stdc++.h>

using namespace std;

void rand_int_out (size_t min, size_t max, size_t N, size_t seed)
{
  static default_random_engine engine (seed);
  static uniform_int_distribution<unsigned> distribution (min, max);

  for (size_t i {0}; i < N; ++i)
    {
      cout << distribution (engine) << " ";
    }
  cout << endl;
}

void rand_int_out (size_t min, size_t max, size_t N)
{
  seed_seq seed = {time (nullptr)};
  static default_random_engine engine (seed);
  static uniform_int_distribution<unsigned> distribution (min, max);

  for (size_t i {0}; i < N; ++i)
    {
      cout << distribution (engine) << " ";
    }
  cout << endl;
}

int main()
try
  {
    rand_int_out (1, 10, 10);
    rand_int_out (1, 10, 10, 1234);
    rand_int_out (1, 10, 10, 1234);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
