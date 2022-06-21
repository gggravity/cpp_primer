#pragma once

#include "quote.h"
#include <bits/stdc++.h>

using namespace std;

class discount_quote : public quote
{
public:

  using quote::quote;

  discount_quote (const discount_quote &other);  // copy constructor

  discount_quote &operator= (const discount_quote &other);  // copy assignment operator

  discount_quote (discount_quote &&other) noexcept;  // move constructor

  discount_quote &operator= (discount_quote &&other) noexcept;  // move assignment operator

  ~discount_quote() override;

  discount_quote (const string &name, double price, size_t quantity, double discount);

  [[nodiscard]] double net_price (size_t count) const override = 0;

  void debug() override;

protected:

  size_t quantity {0};
  double discount {0.0};
};
