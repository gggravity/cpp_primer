#include <bits/stdc++.h>

using namespace std;

struct Sales_data
{
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main (int argc, char *argv[])
try
  {
    Sales_data total;
    double price;

    string file_name {"../input_file.txt"};

    auto ifs = ifstream {file_name};

    if (! ifs)
      {
        cerr << "Error opening file " << file_name;
        exit (EXIT_FAILURE);
      }

    auto ofs = ofstream {argv[1], ofstream::app};

    if (! ofs)
      {
        cerr << "Error opening file " << file_name;
        exit (EXIT_FAILURE);
      }

    if (ifs >> total.bookNo >> total.units_sold >> price)
      {
        total.revenue = price * total.units_sold;
        Sales_data trans;

        while (ifs >> trans.bookNo >> trans.units_sold >> price)
          {
            trans.revenue = price * trans.units_sold;
            if (total.bookNo == trans.bookNo)
              {
                total.revenue += trans.revenue;
                ofs << "adding " << trans.revenue << " to old book revenue"
                    << " for a total of: " << total.revenue << endl;
              }
            else
              {
                ofs << "Book revenue: " << total.revenue << " For: " << total.bookNo << endl;
                total = trans;
              }
          }

        ofs << "Total revenue: " << total.revenue << endl;
      }
    else
      {
        cerr << "No data?!" << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
