#include <iostream>
#include <string>
using namespace std;

// test sting some name blaster faster faster testing test

int main()
{
  string input, last;
  bool not_found = true;

  while (cin >> input && input != ".")
    {
      if (input == last)
        {
          cout << input << " ";
          not_found = false;
          break;
        }
      else
        {
          last = input;
        }
    }
  if (not_found)
    {
      cout << "no results found." << endl;
    }
  return 0;
}
