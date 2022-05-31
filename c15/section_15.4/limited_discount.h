#pragma once

#include <bits/stdc++.h>
#include "discount_quote.h"

using namespace std;

class limited_discount : public discount_quote
   {
   public:

      limited_discount () = default;

      limited_discount (const string &name, double price, size_t quantity, double discount);

      [[nodiscard]] double net_price (size_t count) const override;

      void debug () override;

   };
