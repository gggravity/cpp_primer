#include <iostream>
//#include "Sales_data.h"

using namespace std;

// 0-201-78655 5 98.50
// 0-201-78655 5 98.50

struct Sales_data
    {
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };

int main ()
  {

    Sales_data total;
    double price;

    if (cin >> total.bookNo >> total.units_sold >> price)
      {
        total.revenue = price * total.units_sold;
        Sales_data trans;

        while (cin >> trans.bookNo >> trans.units_sold >> price)
          {
            trans.revenue = price * trans.units_sold;
            if (total.bookNo == trans.bookNo)
              {
                total.revenue += trans.revenue;
                cout << "adding " << trans.revenue
                     << " to old book revenue"
                     << " for a total of: "
                     << total.revenue << endl;
              }
            else
              {
                cout << "Book revenue: " << total.revenue  << " For: " << total.bookNo << endl;
                total = trans;
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
