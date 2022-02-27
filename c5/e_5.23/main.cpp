#include <iostream>

using namespace std;

int main ()
{
  int input1, input2;
  double result{0};

  cout << "Enter two integers and press enter (not zero)." << endl;

  while (cin >> input1 >> input2)
    {
      try
        {
          if (input2 != 0)
            {
              result = static_cast<double> (input1) / input2;
              cout << result << endl;
            }
          else
            {
              throw invalid_argument ("cannot divide by zero\n");
            }
        }
      catch (invalid_argument &error)
        {
          cout << error.what ();
        }
      cout << "Enter two integers and press enter (not zero)." << endl;
    }
  return 0;
}
