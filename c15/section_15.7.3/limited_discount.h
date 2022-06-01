#pragma once

#include <bits/stdc++.h>
#include "discount_quote.h"

using namespace std;

class limited_discount : public discount_quote
   {
   public:

      limited_discount () = default;

      limited_discount (const limited_discount &other); // copy constructor

      limited_discount &operator= (const limited_discount &other); // copy assignment operator

      limited_discount (limited_discount &&other) noexcept; // move constructor

      limited_discount &operator= (limited_discount &&other) noexcept; // move assignment operator

      ~limited_discount () override;

      limited_discount (const string &name, double price, size_t quantity, double discount);

      [[nodiscard]] double net_price (size_t count) const override;

      void debug () override;

   };
