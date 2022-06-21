//
// Created by martin on 28/05/2022.
//

#include <bits/stdc++.h>
#include <ostream>

using namespace std;

// 0-201-78655 5 98.50

class Sales_data
{
public:

  // constructors

  Sales_data();

  Sales_data (string book_number);

  Sales_data (string book_number, unsigned units_sold, double price);

  Sales_data (const char *ISBN);

  explicit Sales_data (istream &is);

  // conversion operators

  explicit operator string() const;

  // methods

  Sales_data &combine (const Sales_data &rhs);

  // getters and setters

  [[nodiscard]] const string &isbn() const;

  void set_isbn (const string &book_no);

  [[nodiscard]] unsigned int units_sold() const;

  void set_units_sold (unsigned int units_sold);

  [[nodiscard]] double revenue() const;

  void set_revenue (double revenue);

  Sales_data &operator+= (const Sales_data &other);

  Sales_data &operator+ (const string &ISBN);

  friend bool operator== (const Sales_data &lhs, const Sales_data &rhs);

  friend bool operator!= (const Sales_data &lhs, const Sales_data &rhs);

private:

  [[nodiscard]] double avg_price() const;

  std::string m_book_no;
  unsigned m_units_sold {0};
  double m_revenue {0.0};

  // friends

  friend Sales_data add (const Sales_data &lhs, const Sales_data &rhs);

  friend istream &read (istream &is, Sales_data &item);

  friend ostream &print (ostream &os, const Sales_data &item);
};

bool operator== (const Sales_data &lhs, const Sales_data &rhs);

bool operator!= (const Sales_data &lhs, const Sales_data &rhs);

istream &operator>> (istream &is, Sales_data &data);

ostream &operator<< (ostream &os, const Sales_data &data);

Sales_data operator+ (const Sales_data &lhs, const Sales_data &rhs);
