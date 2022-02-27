#include <iostream>
#include <vector>

int main()
{
    int array_1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vector_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vector_2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Array 1: ";
    for (int item : array_1)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2: ";
    for (int item : array_2)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector 1: ";
    for (int item : vector_1)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector 2: ";
    for (int item : vector_2)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    int *end = std::end(array_1);
    int *begin = std::begin(array_2);

    while (begin <= end)
    {
        if (array_1[*begin] == array_2[*begin])
        {
            if (*begin == *end)
            {
                std::cout << "Arrays are equal" << std::endl;
            }
            ++begin;
        } else
        {
            std::cout << "Arrays not equal" << std::endl;
            break;
        }
    }

    if (vector_1 == vector_2)
    {
        std::cout << "Vectors are equal" << std::endl;
    }
    else {
        std::cout << "Vectors are not equal" << std::endl;
    }

    return 0;
}
