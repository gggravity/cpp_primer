#include <iostream>

using namespace std;

int factorial (int number)
{
  int result {1};

  while (number > 1)
    {
      result *= number--;
    }

  return result;
}

void interact()
{
  int input {0};

  do
    {
      cout << "Enter a number to calculate the factorial [0 to exit]" << endl;
      cin >> input;
      cout << "The factorial is: " << factorial (input) << endl;
    }
  while (input != 0);
}

int main()
{
  interact();

  return 0;
}
