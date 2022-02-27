#include <iostream>
#include <vector>

int main()
{
    int array[10];

    for (int i = 0; i <= 10; i++)
    {
        array[i] = i;
    }

    for (auto a : array)
    {
        std::cout << a << " ";
    }

    int array_new[10];

    for (int i = 0; i <= 10; i++)
    {
        array_new[i] = array[i];
    }

    std::cout <<std::endl << "The copied array" << std::endl;

    for (auto a : array)
    {
        std::cout << a << " ";
    }

    std::vector<int> vector;

    for(int i = 0; i < 10; ++i)
    {
        vector.push_back(i);
    }

    std::cout <<std::endl << "The content of the vector are" << std::endl;

    for (auto v : vector)
    {
        std::cout << v << " ";
    }

    return 0;
}