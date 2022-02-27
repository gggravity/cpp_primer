#include <iostream>

int main()
{
    std::string string{"Some string"};

    std::cout << string << std::endl;

    for (char &c : string)
    {
        c = 'X';
    }

    std::cout << string << std::endl;

    return 0;
}
