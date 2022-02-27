#include <iostream>

int main()
{
    std::string string{"Some test string"};

    std::cout << string << std::endl;

    for (auto &s : string)
    {
        s = 'X';
    }

    std::cout << string << std::endl;

    return 0;
}
