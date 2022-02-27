#include <iostream>
#include "Sales_data.h"

using namespace std;

// 0-201-78655 5 98.50 0-201-78655 5 98.50

int main ()
{

  Sales_data total;
  double price;

  if (cin >> total.bookNo >> total.units_sold >> price)
    {
      total.revenue = price * total.units_sold;
      Sales_data trans;

      while (cin >> trans.bookNo >> trans.units_sold >> price)
        trans.revenue = price * trans.units_sold;
      {
        if (total.bookNo == trans.bookNo)
          {
            total.revenue += trans.revenue;
          }
        else
          {
            cout << "Book revenue: " << total.revenue << endl;
            total.units_sold += trans.units_sold;
            total.revenue += trans.revenue;

          }
      }
      cout << "Total revenue: " << total.revenue << endl;
    }
  else
    {
      cerr << "No data?!" << endl;
    }
  return 0;
}
