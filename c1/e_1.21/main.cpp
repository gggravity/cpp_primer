#include <iostream>
#include "Sales_item.h"

int main()
{

    //    0-201-78345-X 3 20 0-201-78345-X 3 20
    Sales_item item1;
    Sales_item item2;

    std::cout << "Enter two sales items: " << std::endl;
    std::cin >> item1 >> item2;
    std::cout << "The sum of the two sales item are: ";
    std::cout << item1 + item2 << std::endl;
    return 0;
}
