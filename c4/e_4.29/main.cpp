#include <iostream>

int main()
{
    int x[10];
    int i;
    int *pi;
    int *p;
    std::cout << sizeof(x) / sizeof(*x) << std::endl;
    std::cout << sizeof(p) / sizeof(*p) << std::endl;

    std::cout << "sizeof int: " << sizeof(int) << std::endl;
    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(*x) << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(*p) << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << sizeof(*pi) << std::endl;
    std::cout << sizeof(int*) << std::endl;

    for (auto val : x)
    {
        std::cout << val << " ";
    }

    return 0;
}
