//
// Created by martin on 30-05-22.
//

#include "discount_quote.h"

discount_quote::discount_quote (const discount_quote &other) :
    quote(other),
    quantity(other.quantity),
    discount(other.discount)
  {
    cout << "discount_quote copy constructor called..." << endl;
  }

discount_quote &discount_quote::operator= (const discount_quote &other)
  {
    cout << "discount_quote copy assignment operator called..." << endl;
    quote::operator=(other);
    quantity = other.quantity;
    discount = other.discount;
    return *this;
  }

discount_quote::discount_quote (discount_quote &&other) noexcept :
    quote(std::move(other)),
    quantity(other.quantity),
    discount(other.discount)
  {
    cout << "discount_quote move constructor called..." << endl;
  }

discount_quote &discount_quote::operator= (discount_quote &&other) noexcept
  {
    cout << "discount_quote move assignment operator called..." << endl;
    quantity = other.quantity;
    discount = other.discount;
    quote::operator=(std::move(other));
    return *this;
  }

discount_quote::~discount_quote ()
  {
//    cout << "discount_quote destructor called..." << endl;
  }

discount_quote::discount_quote (const string &name, double price, size_t quantity, double discount) :
    quote(name, price),
    quantity(quantity),
    discount(discount)
  {

  }

//double discount_quote::net_price (size_t count) const
//  {
//    if (count >= 1000)
//      {
//        return double(count) * ( 1 - 0.4 ) * price;
//      }
//    else if (count >= 500)
//      {
//        return double(count) * ( 1 - 0.3 ) * price;
//      }
//    else if (count >= 100)
//      {
//        return double(count) * ( 1 - 0.2 ) * price;
//      }
//    else if (count >= 50)
//      {
//        return double(count) * ( 1 - 0.1 ) * price;
//      }
//    else if (count >= 10)
//      {
//        return double(count) * ( 1 - 0.05 ) * price;
//      }
//    return double(count) * price;
//  }

void discount_quote::debug ()
  {
    cout << "calling discount_quote..." << endl;
  }
