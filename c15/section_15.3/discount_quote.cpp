//
// Created by martin on 30-05-22.
//

#include "discount_quote.h"

discount_quote::discount_quote (const string &name, double price) : quote (name, price) {}

double discount_quote::net_price (size_t count) const
{
  if (count >= 1000)
    {
      return double (count) * (1 - 0.4) * price;
    }
  else if (count >= 500)
    {
      return double (count) * (1 - 0.3) * price;
    }
  else if (count >= 100)
    {
      return double (count) * (1 - 0.2) * price;
    }
  else if (count >= 50)
    {
      return double (count) * (1 - 0.1) * price;
    }
  else if (count >= 10)
    {
      return double (count) * (1 - 0.05) * price;
    }
  return double (count) * price;
}

void discount_quote::debug() { cout << "calling discount_quote..." << endl; }
