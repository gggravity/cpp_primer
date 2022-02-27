#include <iostream>
#include <string>

using namespace std;

// 0-201-78655 5 98.50

struct Sales_data {
    [[nodiscard]] string isbn () const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data &combine (const Sales_data &);
    [[nodiscard]] double avg_price() const;
    static istream &read(istream &is, Sales_data &item);
    static ostream &print(ostream &os, const Sales_data &item);
    static Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

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
  os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
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
  Sales_data total;

  if (Sales_data::read(cin, total))
    {
      Sales_data trans;
      while (Sales_data::read (cin, trans))
      {
        if (total.isbn () == trans.isbn ())
          {
            total.combine (trans);
          }
        else
          {
            Sales_data::print(cout,total);
            total = trans;
          }
      }
      Sales_data::print(cout, total);
    }
  else
    {
      cerr << "No data?!" << endl;
    }

  return 0;
}
