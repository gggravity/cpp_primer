#include <iostream>

int main()
{
    int value1 = 1234;
    int value2 = 4321;

    int *p1 = &value1;
    int *p2 = &value2;


    *p1 = 2222;
    std::cout << "*p = " << *p1 << std::endl;

    *p2 = value1;
    std::cout << "Value 2 = " << *p2 << std::endl;
    return 0;
}
