#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto sum { accumulate(vi.cbegin(), vi.cend(), 0) };
    cout << "sum: " << sum << endl;

    cout << "----" << endl;

    vector<double> v { 1.1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "vd(int): " << accumulate(v.cbegin(), v.cend(), 0) << endl; // init determinate the type
    cout << "vd(double): " << accumulate(v.cbegin(), v.cend(), 0.) << endl; // fixed.

    cout << "----" << endl;

    vector<string> roster1 { "anna", "peter", "paul", "paulina" };
    vector<string> roster2 { "anna", "peter", "paul", "paulina" };
    vector<const char *> roster1c { "anna", "peter", "paul", "paulina" };
    vector<const char *> roster2c { "anna", "peter", "paul", "paulina" };

    cout << boolalpha;
    cout << "equal: " << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;

    // nothing it works fine.
    cout << "equal: " << equal(roster1c.cbegin(), roster1c.cend(), roster2c.cbegin()) << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


