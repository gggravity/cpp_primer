#include <iostream>
#include <string>

using namespace std;

// 0-201-78655 5 98.50

class Sales_data
      {

      public:
            Sales_data ()
                : _bookNo(""),
                  _units_sold(0),
                  _revenue(0)
              {

              }

            explicit Sales_data (const string &book_number)
                : _bookNo(book_number)
              {

              }

            Sales_data (const string &book_number, unsigned units_sold, double price)
                : _bookNo(book_number),
                  _units_sold(units_sold),
                  _revenue(price * units_sold)
              {

              }

            explicit Sales_data (istream &is)
              {
                read(is, *this);
              }

            [[nodiscard]] string isbn () const;

            Sales_data &combine (const Sales_data &);

            [[nodiscard]] inline double avg_price () const;

            static istream &read (istream &is, Sales_data &item);

            static ostream &print (ostream &os, const Sales_data &item);

            static Sales_data add (const Sales_data &lhs, const Sales_data &rhs);

      private:
            std::string _bookNo;
            unsigned _units_sold = 0;
            double _revenue = 0.0;

      };

Sales_data &Sales_data::combine (const Sales_data &rhs)
  {
    _units_sold += rhs._units_sold;
    _revenue += rhs._revenue;
    return *this;
  }

string Sales_data::isbn () const
  {
    return _bookNo;
  }

Sales_data Sales_data::add (const Sales_data &lhs, const Sales_data &rhs)
  {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
  }

istream &Sales_data::read (istream &is, Sales_data &item)
  {
    double price { 0 };
    is >> item._bookNo >> item._units_sold >> price;
    item._revenue = item._units_sold * price;
    return is;
  }

ostream &Sales_data::print (ostream &os, const Sales_data &item)
  {
    os << item._bookNo << " " << item._units_sold << " " << item._revenue << " " << item.avg_price();
    return os;
  }

inline double Sales_data::avg_price () const
  {
    if (_units_sold)
      {
        return _revenue / _units_sold;
      }
    else
      {
        return 0;
      }
  }

int main ()
  {
    Sales_data sales_data("0-201-78655", 5, 98.50);
    Sales_data::print(cout, sales_data);

    return 0;
  }