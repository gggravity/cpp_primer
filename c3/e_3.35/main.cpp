#include <iostream>

int main()
{
    int array[33];

    int *b = std::begin(array);
    int *e = std::end(array);

    for (; b < e; b++)
    {
        *b = 0;
    }

    for (int a : array)
    {
        std::cout << a << " ";
    }

    return 0;
}
