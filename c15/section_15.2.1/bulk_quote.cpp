//
// Created by martin on 30-05-22.
//

#include "bulk_quote.h"

double bulk_quote::net_price (size_t n) const
  {
    return quote::net_price(n);
  }
