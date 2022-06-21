#pragma once

#include "quote.h"
#include <bits/stdc++.h>

using namespace std;

class bulk_quote : public quote
{
public:

  [[nodiscard]] double net_price (size_t n) const override;
};
