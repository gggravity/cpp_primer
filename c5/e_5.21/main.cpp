#include <iostream>
#include <string>
using namespace std;

// match match semi automatic star fleet Fleet Star Star someone is lying .

int main()
{
  string buffer, last_word;
  bool not_found = true;

  while (cin >> buffer && buffer != ".")
    {
      if (! isupper (buffer[0]))
        {
          continue;
        }
      if (buffer == last_word)
        {
          cout << buffer;
          not_found = false;
          break;
        }
      else
        {
          last_word = buffer;
        }
    }
  if (not_found)
    {
      cout << "No match found.";
    }

  return 0;
}
