//
// Created by martin on 31-05-22.
//

#include "limited_discount.h"

limited_discount::limited_discount (const limited_discount &other) : discount_quote (other)
{
  cout << "limited_discount copy constructor called..." << endl;
}

limited_discount &limited_discount::operator= (const limited_discount &other)
{
  cout << "limited_discount copy assignment operator called..." << endl;
  discount_quote::operator= (other);
  return *this;
}

limited_discount::limited_discount (limited_discount &&other) noexcept : discount_quote (std::move (other))
{
  cout << "limited_quote move constructor called..." << endl;
}

limited_discount &limited_discount::operator= (limited_discount &&other) noexcept
{
  cout << "limited_quote move assignment operator called..." << endl;
  discount_quote::operator= (std::move (other));
  return *this;
}

limited_discount::~limited_discount() { cout << "limited_quote destructor called..." << endl; }

limited_discount::limited_discount (const string &name, double price, size_t quantity, double discount)
    : discount_quote (name, price, quantity, discount)
{
}

double limited_discount::net_price (size_t count) const
{
  //    cout << "calling limited_discount..." << endl;
  if (count < quantity)
    {
      return price * int (count);
    }
  else
    {
      double sum {int (quantity) * price * discount};
      count -= quantity;
      sum += int (count) * price;
      return sum;
    }
}

void limited_discount::debug() { cout << "calling discount_quote..." << endl; }
