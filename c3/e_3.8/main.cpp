#include <iostream>

int main()
{
    std::string string{"some test sting"};


    std::cout << string << std::endl;
    int i = 0;
    while (i < string.size())
    {
        string[i] = 'X';
        i++;
    }
    std::cout << string << std::endl;

    string = "something to write about";
    std::cout << string << std::endl;
    for (int j = 0; j <= string.size(); ++j)
    {
        string[j] = 'X';
    }
    std::cout << string << std::endl;

    return 0;
}
