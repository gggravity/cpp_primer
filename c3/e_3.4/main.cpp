#include <iostream>

using namespace std;

int main()
{
  string s1;
  string s2;

  cin >> s1 >> s2;
  if (s1 == s2)
    {
      cout << "The strings are equal." << endl;
    }
  else
    {
      if (s1 > s2)
        {
          cout << "s1 larger then s2." << endl;
        }
      else
        {
          cout << "s2 larger then s1." << endl;
        }
      if (s1.length() > s2.length())
        {
          cout << "s1 longer then s2." << endl;
        }
      else
        {
          cout << "s1 longer then s2." << endl;
        }
    }

  return 0;
}
