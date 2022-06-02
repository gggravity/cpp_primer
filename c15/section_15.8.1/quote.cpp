//
// Created by martin on 30-05-22.
//

#include "quote.h"

quote::quote (string book_number, double price) :
    book_number(std::move(book_number)),
    price(price)
  {

  }

string quote::isbn () const
  {
    return book_number;
  }

double quote::net_price (size_t count) const
  {
    return double(count) * price;
  }

void quote::debug ()
  {
    cout << "calling quote..." << endl;
  }

quote::quote (const quote &other) :
    price(other.price),
    book_number(other.book_number)
  {
    cout << "quote copy constructor called..." << endl;
  }

quote &quote::operator= (const quote &other)
  {
    cout << "quote copy assignment operator called..." << endl;
    price = other.price;
    book_number = other.book_number;

    return *this;
  }

quote::quote (quote &&other) noexcept :
    price(other.price),
    book_number(std::move(other.book_number))
  {
    cout << "quote move constructor called..." << endl;
  }

quote &quote::operator= (quote &&other) noexcept
  {
    cout << "quote move assignment operator called..." << endl;
    price = other.price;
    book_number = std::move(other.book_number);
    return *this;
  }

quote *quote::clone () const &
  {
    return new quote(*this);
  }

quote *quote::clone () &&
  {
    return new quote(std::move(*this));
  }

  quote::~quote ()
    {
//      cout << "quote destructor called..." << endl;
    }

double print_total (ostream &os, const quote &item, size_t n)
  {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
  }
