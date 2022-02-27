#include <iostream>
#include "Sales_item.h"
int main()
{
//    0-201-78345-X 3 20
    Sales_item item;
    Sales_item item_sum;

    std::cout << "Enter a sales item to sum:" << std::endl;
    while (std::cin >> item)
    {
        item_sum += item;
        std::cout << "The total of all sales item entered are: " << item_sum << std::endl;
    }
    return 0;
}
