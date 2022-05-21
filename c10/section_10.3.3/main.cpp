#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    // e 10.20
    vector<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    vector<string>::size_type sz { 5 };

    auto count = count_if(words.begin(), words.end(), [sz] (const string &s)
      {
          return s.size() > sz;
      });

    cout << count << " are larger then " << sz << " characters." << endl;

    // e 10.21

    cout << boolalpha << [sz] () mutable -> bool
      {
          while (sz > 0)
            {
              --sz;
              cout << sz << " ";
            }
            cout << endl;
            return true;
      }();

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


