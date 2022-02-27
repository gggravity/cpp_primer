#include <iostream>

using namespace std;

inline bool isShorter (const string &s1, const string &s2)
{
  return s1.size () < s2.size ();
}

int main ()
{
  string string1{"some string"};
  string string2{"some long string"};

  cout << isShorter(string1, string2) << endl;

  return 0;
}
