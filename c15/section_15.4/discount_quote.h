#pragma once

#include "quote.h"
#include <bits/stdc++.h>

using namespace std;

class discount_quote : public quote
{
public:

  discount_quote() = default;

  discount_quote (const string &name, double price, size_t quantity, double discount);

  [[nodiscard]] double net_price (size_t count) const override = 0;

  void debug() override;

protected:

  size_t quantity {0};
  double discount {0.0};
};
