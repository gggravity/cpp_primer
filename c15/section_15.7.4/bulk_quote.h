#pragma once

#include "discount_quote.h"
#include <bits/stdc++.h>

using namespace std;

class bulk_quote : public discount_quote
{
public:

  using discount_quote::discount_quote;

  bulk_quote (const bulk_quote &other);  // copy constructor

  bulk_quote &operator= (const bulk_quote &other);  // copy assignment operator

  bulk_quote (bulk_quote &&other) noexcept;  // move constructor

  bulk_quote &operator= (bulk_quote &&other) noexcept;  // move assignment operator

  ~bulk_quote() override;

  bulk_quote (const string &name, double price, size_t quantity, double discount);

  [[nodiscard]] double net_price (size_t count) const override;

  void debug() override;
};
