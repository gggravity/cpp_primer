#include <iostream>

int main()
{
    std::string string;
    while (std::cin >> string && string != "42")
    {
        std::cout << string << std::endl;
    }
    return 0;
}
