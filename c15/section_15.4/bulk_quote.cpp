//
// Created by martin on 30-05-22.
//

#include "bulk_quote.h"

bulk_quote::bulk_quote (const string &name, double price, size_t quantity, double discount)
    : discount_quote (name, price, quantity, discount)
{
}

double bulk_quote::net_price (size_t count) const
{
  if (count >= quantity)
    {
      return double (count) * (1 - discount) * price;
    }
  else
    {
      return double (count) * price;
    }
}

void bulk_quote::debug() { cout << "calling bulk_quote..." << endl; }
