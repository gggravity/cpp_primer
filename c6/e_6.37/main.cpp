#include <iostream>

using namespace std;

string (&func())[10];

// typedef string string_array[10];
// using string_array = string[10];

string_array &func();

auto func() -> string (&)[10];

string string_array[10] = {};
decltype (string_array) &func();

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
