#include <iostream>

int main()
{
    std::string s = "word";
    std::string pl = s + (s[s.size() - 1] == 's' ? "" : "s");

    std::cout << pl;

    return 0;
}
