#include <iostream>
#include <vector>

int main()
{
    int arr[] = {1, 2 ,3 ,4 ,5, 6};
    std::vector<int> vec;

    int *begin = std::begin(arr);
    int *end = std::end(arr);


    while (begin < end){
        vec.push_back(*begin);
        ++begin;
    }

    for (auto v : vec)
    {
        std::cout << v << " ";
    }

    return 0;
}
