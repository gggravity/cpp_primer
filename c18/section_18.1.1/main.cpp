#include <bits/stdc++.h>

using namespace std;

struct Deleter
    {
        void operator() (const int *p)
          {
            cout << "deleting int[]" << endl;
            delete[] p;
          }

    };

void exercise (int *b, int *e)
  {
    vector<int> v(b, e);
//    int *p = new int[v.size()];
//    auto p = make_unique<int[]>(v.size());
    auto p = unique_ptr<int[], Deleter>(new int[v.size()]);

    ifstream in("ints");

    // exception occurs here
    throw runtime_error("something went wrong");
  }

int main ()
try
  {
    range_error r { "error" };
//    throw r; // Clang-Tidy: Throw expression should throw anonymous temporary values instead

    exception *p = &r; // std::exception

//    throw *p;

//    Clang-Tidy: Throw expression should throw anonymous temporary values instead
//    Clang-Tidy: Throw expression throws a pointer; it should throw a non-pointer value instead
//    Clang-Tidy: Throwing an exception whose type 'std::exception *' is not derived from 'std::exception'

//    throw p; // terminate called after throwing an instance of 'std::exception*'

    exercise(nullptr, nullptr);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


