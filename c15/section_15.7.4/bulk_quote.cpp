//
// Created by martin on 30-05-22.
//

#include "bulk_quote.h"

bulk_quote::bulk_quote (const bulk_quote &other) :
    discount_quote(other)
  {
    cout << "bulk_quote copy constructor called..." << endl;
  }

bulk_quote &bulk_quote::operator= (const bulk_quote &other)
  {
    cout << "bulk_quote copy assignment operator called..." << endl;
    discount_quote::operator=(other);
    return *this;
  }

bulk_quote::bulk_quote (bulk_quote &&other) noexcept :
    discount_quote(std::move(other))
  {
    cout << "bulk_quote move constructor called..." << endl;
  }

bulk_quote &bulk_quote::operator= (bulk_quote &&other) noexcept
  {
    cout << "bulk_quote move assignment operator called..." << endl;
    discount_quote::operator=(std::move(other));
    return *this;
  }

bulk_quote::~bulk_quote ()
  {
    cout << "bulk_quote destructor called..." << endl;
  }


bulk_quote::bulk_quote (const string &name, double price, size_t quantity, double discount) :
    discount_quote(name, price, quantity, discount)
  {

  }

double bulk_quote::net_price (size_t count) const
  {
    if (count >= quantity)
      {
        return double(count) * ( 1 - discount ) * price;
      }
    else
      {
        return double(count) * price;
      }
  }

void bulk_quote::debug ()
  {
    cout << "calling bulk_quote..." << endl;
  }

