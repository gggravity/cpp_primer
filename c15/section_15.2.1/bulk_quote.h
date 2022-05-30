#pragma once

#include <bits/stdc++.h>
#include "quote.h"

using namespace std;

class bulk_quote : public quote
   {
   public:
      [[nodiscard]] double net_price (size_t n) const override;

   };
