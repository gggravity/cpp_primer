#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{

  for (size_t i = 1; i != argc; i++ )
    cout << "Argument " << i << " = " << argv[i] << endl;

  return 0;
}
