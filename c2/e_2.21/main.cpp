#include <iostream>

int main()
{
    int i = 0;
//    double *dp = &i; // error point to int
//    int *ip = i; // error don't point.
    int *p = &i;
    std::cout << "*p with the value: " << *p << " located at: " << p << std::endl;
    return 0;
}
