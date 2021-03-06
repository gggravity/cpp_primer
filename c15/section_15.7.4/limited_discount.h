#pragma once

#include "discount_quote.h"
#include <bits/stdc++.h>

using namespace std;

class limited_discount : public discount_quote
{
public:

  using discount_quote::discount_quote;

  limited_discount (const limited_discount &other);  // copy constructor

  limited_discount &operator= (const limited_discount &other);  // copy assignment operator

  limited_discount (limited_discount &&other) noexcept;  // move constructor

  limited_discount &operator= (limited_discount &&other) noexcept;  // move assignment operator

  ~limited_discount() override;

  limited_discount (const string &name, double price, size_t quantity, double discount);

  [[nodiscard]] double net_price (size_t count) const override;

  void debug() override;
};
