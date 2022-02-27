#include <iostream>

int main()
{
//    int i = -1, &r = 0; // error with &r
//    int i2;
//    int *const p2 = &i2;
//    const int i = -1, &r = 0;
//    const int *const p3 = &i2;
//    const int *p1 = &i2;
//    const int &const r2;
    const int i2 = i;
    const int &r = i;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
