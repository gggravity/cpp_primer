#include <iostream>

int main()
{
    int a = 4;
    int b = 3;
    int c = 2;
    int d = 1;

    if (a > b && b > c && c > d)
        std::cout << "Hello, World!" << std::endl;
    else
        std::cout << "Hello, Void!" << std::endl;

    return 0;
}
