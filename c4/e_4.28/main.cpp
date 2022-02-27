#include <iostream>

int main()
{
    std::cout << "Signed and unsigned integer types" << std::endl;
    std::cout << "short int: " << sizeof(short int) << std::endl;
    std::cout << "signed short: " << sizeof(signed short) << std::endl;
    std::cout << "signed short int: " << sizeof(signed short int) << std::endl;
    std::cout << "unsigned short: " << sizeof(unsigned short) << std::endl;
    std::cout << "unsigned short int: " << sizeof(unsigned short int) << std::endl;
    std::cout << "signed: " << sizeof(signed) << std::endl;
    std::cout << "signed int: " << sizeof(signed int) << std::endl;
    std::cout << "unsigned: " << sizeof(unsigned) << std::endl;
    std::cout << "unsigned int: " << sizeof(unsigned int) << std::endl;
    std::cout << "long: " << sizeof(long) << std::endl;
    std::cout << "long int: " << sizeof(long int) << std::endl;
    std::cout << "signed long: " << sizeof(signed long) << std::endl;

    return 0;
}
