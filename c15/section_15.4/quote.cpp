//
// Created by martin on 30-05-22.
//

#include "quote.h"

quote::quote (string book_number, double price) : book_number (std::move (book_number)), price (price) {}

string quote::isbn() const { return book_number; }

double quote::net_price (size_t count) const { return double (count) * price; }

void quote::debug() { cout << "calling quote..." << endl; }

double print_total (ostream &os, const quote &item, size_t n)
{
  double ret = item.net_price (n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}