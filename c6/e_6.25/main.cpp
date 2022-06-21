#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
  string str1, str2, concat_string;

  str1 = argv[1];
  str2 = argv[2];
  concat_string = str1 + str2;

  cout << concat_string << endl;

  return 0;
}
