#pragma once
//
// Created by martin on 02-06-22.
//
#include <bits/stdc++.h>
#include "quote.h"

using namespace std;

class basket
   {
   public:
      void add_item (const shared_ptr<quote> &sale);

      void add_item (const quote &sale);

      void add_item (quote &&sale);

      double total_receipt (ostream &os) const;

   private:
      static bool compare (const shared_ptr<quote> &lhs, const shared_ptr<quote> &rhs);

      multiset<shared_ptr<quote>, decltype(compare) *> items { compare };

   };

