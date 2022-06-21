#pragma once

#include "discount_quote.h"
#include <bits/stdc++.h>

using namespace std;

class bulk_quote : public discount_quote
{
public:

  bulk_quote() = default;

  bulk_quote (const string &name, double price, size_t quantity, double discount);

  [[nodiscard]] double net_price (size_t count) const override;

  void debug() override;
};
