#include <iostream>
#include <bitset>

int main()
{
    unsigned long quiz1 = 0;
    unsigned int quiz2 = 0;
    quiz1 |= 1UL << 27;
    quiz2|= 1UL << 27;
    std::cout << "quiz1 = " << std::bitset<32>(quiz1) << std::endl;
    std::cout << "quiz2 = " << std::bitset<16>(quiz2) << std::endl; // int only guarantied to have 16 bit
    return 0;
}
