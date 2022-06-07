
//
// Created by martin on 28/05/2022.
//

#include <bits/stdc++.h>

using namespace std;

class SalesData
   {
   public:
      // constructors

      SalesData ()
          : SalesData("", 0, 0)
        {
        }

      SalesData (string book_number)
          : SalesData(std::move(book_number), 0, 0)
        {
        }

      SalesData (string book_number, unsigned units_sold, double price)
          : m_book_no(std::move(book_number)),
          m_units_sold(units_sold),
          m_revenue(price * units_sold)
        {
        }

      SalesData (const char *ISBN) :
          m_book_no(ISBN)
        {

        }

      explicit SalesData (istream &is)
          : SalesData()
        {
          cout << "istream constructor used" << endl;
          read(is, *this);
        }

      // conversion operators

      explicit operator string () const
        {
          return isbn();
        }

      // methods

      SalesData &combine (const SalesData &rhs)
        {
          m_units_sold += rhs.units_sold();
          m_revenue += rhs.revenue();
          return *this;
        }

      // getters and setters

      [[nodiscard]] const string &isbn () const
        {
          return m_book_no;
        }

      void set_isbn (const string &book_no)
        {
          m_book_no = book_no;
        }

      [[nodiscard]] unsigned int units_sold () const
        {
          return m_units_sold;
        }

      void set_units_sold (unsigned int units_sold)
        {
          m_units_sold = units_sold;
        }

      [[nodiscard]] double revenue () const
        {
          return m_revenue;
        }

      void set_revenue (double revenue)
        {
          m_revenue = revenue;
        }

      SalesData &operator+= (const SalesData &other)
        {
          if (isbn() != other.isbn())
            {
              throw runtime_error("can't add different books");
            }

          *this = *this + other;
          return *this;
        }

      SalesData &operator+ (const string &ISBN)
        {
          set_isbn(ISBN);
          return *this;
        }

      SalesData operator+ (const SalesData &other)
        {
          if (this->isbn() != other.isbn())
            {
              throw runtime_error("can't add different books");
            }

          set_units_sold(units_sold() + other.units_sold());
          set_revenue(revenue() + other.revenue());

          return *this;
        }

      friend bool operator== (const SalesData &lhs, const SalesData &rhs);

      friend bool operator!= (const SalesData &lhs, const SalesData &rhs);

   private:

      [[nodiscard]] double avg_price () const
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

      std::string m_book_no;
      unsigned m_units_sold { 0 };
      double m_revenue { 0.0 };

      // friends

      friend SalesData add (const SalesData &lhs, const SalesData &rhs);

      friend istream &read (istream &is, SalesData &item);

      friend ostream &print (ostream &os, const SalesData &item);

   };

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

//inline SalesData operator+ (const SalesData &lhs, const SalesData &rhs)
//  {
//    SalesData sum = lhs;
//    sum += rhs;
//
//    return sum;
//  }

/***

DEFINITIONS

*/


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

inline bool compare_ISBN (const SalesData &lhs, const SalesData &rhs)
  {
    return lhs.isbn() < rhs.isbn();
  }


// hash function for unordered multiset.

namespace std
  {
    template <>
    struct hash<SalesData>
        {
            typedef size_t result_type;
            typedef SalesData argument_type;

            size_t operator() (const SalesData &s) const;
        };

    size_t hash<SalesData>::operator() (const SalesData &s) const
      {
        return hash<string>()(s.isbn()) ^
               hash<unsigned>()(s.units_sold()) ^
               hash<double>()(s.revenue());
      }
  }


