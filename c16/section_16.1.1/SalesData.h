//
// Created by martin on 28/05/2022.
//

#include <bits/stdc++.h>
#include <ostream>

using namespace std;

// 0-201-78655 5 98.50

class SalesData
   {
   public:
      // constructors

      SalesData ();

      SalesData (string book_number);

      SalesData (string book_number, unsigned units_sold, double price);

      SalesData (const char *ISBN);

      explicit SalesData (istream &is);

      // conversion operators

      explicit operator string() const;

      // methods

      SalesData &combine (const SalesData &rhs);

      // getters and setters

      [[nodiscard]] const string &isbn () const;

      void set_isbn (const string &book_no);

      [[nodiscard]] unsigned int units_sold () const;

      void set_units_sold (unsigned int units_sold);

      [[nodiscard]] double revenue () const;

      void set_revenue (double revenue);

      SalesData &operator+= (const SalesData &other);

      SalesData &operator+ (const string &ISBN);

      friend bool operator== (const SalesData &lhs, const SalesData &rhs);

      friend bool operator!= (const SalesData &lhs, const SalesData &rhs);



   private:

      [[nodiscard]] double avg_price () const;

      std::string m_book_no;
      unsigned m_units_sold { 0 };
      double m_revenue { 0.0 };

      // friends

      friend SalesData add (const SalesData &lhs, const SalesData &rhs);

      friend istream &read (istream &is, SalesData &item);

      friend ostream &print (ostream &os, const SalesData &item);

   };

bool operator== (const SalesData &lhs, const SalesData &rhs);

bool operator!= (const SalesData &lhs, const SalesData &rhs);

istream &operator>> (istream &is, SalesData &data);

ostream &operator<< (ostream &os, const SalesData &data);

SalesData operator+ (const SalesData &lhs, const SalesData &rhs);
