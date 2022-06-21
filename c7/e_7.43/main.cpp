#include <bits/stdc++.h>

using namespace std;

class NoDefault
{
public:

  NoDefault (int i) { cout << "NoDefault constructed" << endl; }
};

class C
{
public:

  C() : no_default (0) { cout << "C constructed" << endl; }

private:

  NoDefault no_default;
};

int main()
try
  {
    //    NoDefault no_default;
    C c;

    //     vector<NoDefault> vec(10); // no matching constructor for initialization of 'NoDefault'

    vector<C> vec_of_C (10);  // C and NoDefault constructed 11 times each.

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
