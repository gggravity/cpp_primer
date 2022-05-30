#pragma once

#include <bits/stdc++.h>
#include "quote.h"

using namespace std;

class discount_quote : public quote
   {
   public:
      discount_quote (const string &name, double price);

      [[nodiscard]] double net_price (size_t count) const override;

   };
