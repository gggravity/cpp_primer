//
// Created by martin on 16/05/2022.
//

#include "Sales_data.h"

Sales_data::Sales_data() : Sales_data ("", 0, 0)
{
  //    cout << "0 Arg constructor" << endl;
}

Sales_data &Sales_data::combine (const Sales_data &rhs)
{
  m_units_sold += rhs.units_sold();
  m_revenue += rhs.revenue();
  return *this;
}

Sales_data add (const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.combine (rhs);
  return sum;
}

istream &read (istream &is, Sales_data &item)
{
  double price {0};
  is >> item.m_book_no >> item.m_units_sold >> price;
  item.m_revenue = item.m_units_sold * price;
  return is;
}

ostream &print (ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold() << " " << item.revenue() << " " << item.avg_price();
  return os;
}

double Sales_data::avg_price() const
{
  if (units_sold())
    {
      return revenue() / units_sold();
    }
  else
    {
      return 0;
    }
}

Sales_data::Sales_data (string book_number, unsigned int units_sold, double price)
    : m_book_no (std::move (book_number)), m_units_sold (units_sold), m_revenue (price * units_sold)
{
  //    cout << "3 arg constructor" << endl;
}

Sales_data::Sales_data (string book_number) : Sales_data (std::move (book_number), 0, 0)
{
  //    cout << "Using string constructor" << endl;
}

Sales_data::Sales_data (istream &is) : Sales_data()
{
  cout << "istream constructor used" << endl;
  read (is, *this);
}

const string &Sales_data::isbn() const { return m_book_no; }

void Sales_data::set_isbn (const string &book_no) { m_book_no = book_no; }

unsigned int Sales_data::units_sold() const { return m_units_sold; }

void Sales_data::set_units_sold (unsigned int units_sold) { m_units_sold = units_sold; }

double Sales_data::revenue() const { return m_revenue; }

void Sales_data::set_revenue (double revenue) { m_revenue = revenue; }
