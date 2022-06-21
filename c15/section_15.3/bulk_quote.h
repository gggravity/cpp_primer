#pragma once

#include "quote.h"
#include <bits/stdc++.h>

using namespace std;

class bulk_quote : public quote
{
public:

  bulk_quote() = default;

  bulk_quote (const string &name, double price, size_t quantity, double discount);

  [[nodiscard]] double net_price (size_t count) const override;

  void debug() override;

private:

  size_t min_quantity {0};
  double discount {0.0};
};
