#include <iostream>

using namespace std;

int main()
{
  string s;

  // part 1
  while (getline (cin, s))
    {
      cout << s << endl;
    }

  // part 2

  while (cin >> s)
    {
      cout << s << endl;
    }

  return 0;
}
