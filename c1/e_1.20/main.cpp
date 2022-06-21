#include "Sales_item.h"
#include <iostream>

int main()
{
  //    0-201-78345-X 3 20
  Sales_item book;
  std::cout << "Enter book info: " << std::endl;

  while (std::cin >> book)
    {
      std::cout << "Printing book info: " << book << std::endl;
    }

  return 0;
}
