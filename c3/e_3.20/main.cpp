#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vector = {12, 23, 34, 56, 73, 54, 24, 76};

    for (int i = 0; i < vector.size()-1 ; ++i)
    {
        std::cout << vector[i]  << " + " << vector[i+1] << " = ";
        std::cout << vector[i] + vector[i+1] << std::endl;
    }

    std::cout << std::endl << "--------" << std::endl;

    for (int i = 0; i < (vector.size())/2 ; ++i)
    {
        std::cout << vector[i]  << " + " << vector[vector.size()-i-1] << " = ";
        std::cout << vector[i] + vector[vector.size()-1-1] << std::endl;
    }

    return 0;
}
