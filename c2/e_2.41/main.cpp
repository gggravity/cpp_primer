#include <iostream>
#include "Sales_data.h"

int main()
{
    double price = 123.4;
    Sales_data data1;
    Sales_data data2;
    Sales_data data3;


    data1.bookNo = "0-201-78655";
    data1.units_sold = 123;
    data1.revenue = price * data1.units_sold;
    std::cout << "Book ISBN: " << data1.bookNo << std::endl;
    std::cout << "Total revenue: " << data1.revenue << std::endl;

    std::cout << std::endl;

    data2.bookNo = "0-201-78655";
    data2.units_sold = 321;
    data2.revenue = price * data2.units_sold;

    if (data1.bookNo == data2.bookNo)
    {
        std::cout << "Book ISBN: " << data1.bookNo << std::endl;
        std::cout << "Total revenue: " << data1.revenue + data2.revenue << std::endl;
    } else
    {
        std::cout << "The books is not identical." << std::endl;
    }

    std::cout << std::endl;

    data3.bookNo = "0-201-78655";
    data3.units_sold = 9999;
    data3.revenue = price * data2.units_sold;

    if (data1.bookNo == data2.bookNo)
    {
        std::cout << "Book ISBN: " << data1.bookNo << std::endl;
        std::cout << "Total revenue: " << data1.revenue + data2.revenue + data3.revenue << std::endl;
    } else
    {
        std::cout << "The books is not identical." << std::endl;
    }

    return 0;
}
