#include <iostream>

using namespace std;

void using_capital_letters (const string &string)
{
  bool match = false;

  for (auto c : string)
    {
      if (isupper (c))
        {
          cout << "The string contains the capital letter: " << c << endl;
          match = true;
          break;
        }
    }

  if (! match)
    {
      cout << "The string doesn't contain any capital letters." << endl;
    }
}

void string_to_lowercase (string &string)
{
  for (auto &c : string)
    {
      c = tolower (c);
    }
}

int main()
{
  string string1 {"Der var en gang en mand."};
  string string2 {"der var en gang en mand."};

  using_capital_letters (string1);
  using_capital_letters (string2);

  string_to_lowercase (string1);
  string_to_lowercase (string2);

  cout << string1 << endl;
  cout << string2 << endl;

  return 0;
}
