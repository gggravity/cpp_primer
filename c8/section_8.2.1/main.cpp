#include <bits/stdc++.h>

using namespace std;

struct Sales_data
    {
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };


int main ()
try
  {

//    string file_name { "../input_file.txt" };
//
//    auto ifs = ifstream { file_name };
//
//    if (!ifs)
//      {
//        cerr << "Error opening file " << file_name;
//        exit(EXIT_FAILURE);
//      }
//
//    vector<string> vec;
//    for (string input ; !ifs.eof() ;)
//      {
////        getline(ifs, input);
//        ifs >> input;
//        vec.push_back(input);
//      }
//
//    for (const auto &item : vec)
//      {
//        cout << item << endl;
//      }

    Sales_data total;
    double price;

    string file_name { "../input_file_2.txt" };

    auto ifs = ifstream { file_name };

    if (!ifs)
      {
        cerr << "Error opening file " << file_name;
        exit(EXIT_FAILURE);
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
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
