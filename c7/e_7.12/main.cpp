#include <iostream>
#include <string>

using namespace std;

// 0-201-78655 5 98.50

struct Sales_data {

    Sales_data () = default;
    explicit Sales_data (const string &s)
        : bookNo (s)
    {}
    Sales_data (const string &s, unsigned n, double p)
        : bookNo (s), units_sold (n), revenue (p * n)
    {}
    explicit Sales_data (istream &is)
    {
      read (is, *this);
    }

    [[nodiscard]] string isbn () const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data &combine (const Sales_data &);
    [[nodiscard]] double avg_price () const;
    static istream &read (istream &is, Sales_data &item);
    static ostream &print (ostream &os, const Sales_data &item);
    static Sales_data add (const Sales_data &lhs, const Sales_data &rhs);
};

Sales_data &Sales_data::combine (const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

string Sales_data::isbn () const
{
  return bookNo;
}
Sales_data Sales_data::add (const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.combine (rhs);
  return sum;
}
istream &Sales_data::read (istream &is, Sales_data &item)
{
  double price{0};
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}
ostream &Sales_data::print (ostream &os, const Sales_data &item)
{
  os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price ();
  return os;
}
double Sales_data::avg_price () const
{
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}

int main ()
{
  Sales_data data1;
  Sales_data data2 ("0-201-78655");
  Sales_data data3 ("0-201-78655", 3, 33.98);
  Sales_data data4 (cin);

  Sales_data::print (cout, data1);
  cout << endl;
  Sales_data::print (cout, data2);
  cout << endl;
  Sales_data::print (cout, data3);
  cout << endl;
  Sales_data::print (cout, data4);

  return 0;
}
