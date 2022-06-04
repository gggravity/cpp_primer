//
// Created by martin on 28/05/2022.
//

#include "SalesData.h"

SalesData::SalesData ()
    : SalesData("", 0, 0)
  {
//    cout << "0 Arg constructor" << endl;
  }

SalesData &SalesData::combine (const SalesData &rhs)
  {
    m_units_sold += rhs.units_sold();
    m_revenue += rhs.revenue();
    return *this;
  }

SalesData add (const SalesData &lhs, const SalesData &rhs)
  {
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
  }

istream &read (istream &is, SalesData &item)
  {
    double price { 0 };
    is >> item.m_book_no >> item.m_units_sold >> price;
    item.m_revenue = item.m_units_sold * price;
    return is;
  }

ostream &print (ostream &os, const SalesData &item)
  {
    os << item.isbn() << " " << item.units_sold() << " " << item.revenue() << " " << item.avg_price();
    return os;
  }

double SalesData::avg_price () const
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

SalesData::SalesData (string book_number, unsigned int units_sold, double price)
    : m_book_no(std::move(book_number)),
    m_units_sold(units_sold),
    m_revenue(price * units_sold)
  {
//    cout << "3 arg constructor" << endl;
  }

SalesData::SalesData (string book_number)
    : SalesData(std::move(book_number), 0, 0)
  {
//    cout << "Using string constructor" << endl;
  }

SalesData::SalesData (istream &is)
    : SalesData()
  {
    cout << "istream constructor used" << endl;
    read(is, *this);
  }

const string &SalesData::isbn () const
  {
    return m_book_no;
  }

void SalesData::set_isbn (const string &book_no)
  {
    m_book_no = book_no;
  }

unsigned int SalesData::units_sold () const
  {
    return m_units_sold;
  }

void SalesData::set_units_sold (unsigned int units_sold)
  {
    m_units_sold = units_sold;
  }

double SalesData::revenue () const
  {
    return m_revenue;
  }

void SalesData::set_revenue (double revenue)
  {
    m_revenue = revenue;
  }

SalesData &SalesData::operator+= (const SalesData &other)
  {
    if (isbn() != other.isbn())
      {
        throw runtime_error("can't add different books");
      }
    *this = *this + other;
    return *this;
  }

istream &operator>> (istream &is, SalesData &data)
  {
    char c1;
    char c2;
    string isbn;
    int units_sold;
    double revenue;

    is >> c1 >> isbn >> units_sold >> revenue >> c2;

    if (c1 != '{' || c2 != '}' || !isalnum(isbn[0]))
      {
        throw runtime_error("bad input. format needed { ISBN UNITS REVENUE }");
        return is;
      }

    data.set_isbn(isbn);
    data.set_units_sold(units_sold);
    data.set_revenue(revenue);

    return is;
  }

ostream &operator<< (ostream &os, const SalesData &data)
  {
    os << "isbn: " << data.isbn() << " units_sold: " << data.units_sold() << " revenue: " << data.revenue();
    return os;
  }

SalesData operator+ (const SalesData &lhs, const SalesData &rhs)
  {
    if (lhs.isbn() != rhs.isbn())
      {
        throw runtime_error("can't add different books");
      }

    SalesData sd;

    sd.set_isbn(lhs.isbn());
    sd.set_units_sold(lhs.units_sold() + rhs.units_sold());
    sd.set_revenue(lhs.revenue() + rhs.units_sold());

    return sd;
  }

bool operator== (const SalesData &lhs, const SalesData &rhs)
  {
    return lhs.m_book_no == rhs.m_book_no &&
           lhs.m_units_sold == rhs.m_units_sold &&
           lhs.m_revenue == rhs.m_revenue;
  }

bool operator!= (const SalesData &lhs, const SalesData &rhs)
  {
    return !( rhs == lhs );
  }

SalesData &SalesData::operator+ (const string &ISBN)
  {
    set_isbn(ISBN);
    return *this;
  }

SalesData::SalesData (const char *ISBN) :
    m_book_no(ISBN)
  {

  }

SalesData::operator string () const
  {
    return isbn();
  }
