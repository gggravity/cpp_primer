#include <iostream>

using namespace std;

void error_msg(ErrCode e, initializer_list<string> il)
{
  cout << e.msg() << ": ";
  for (const auto &elem : il) // const basic_string<char> &elem
    cout << elem << " ";
  cout << endl;
}


int main ()
{
  return 0;
}
