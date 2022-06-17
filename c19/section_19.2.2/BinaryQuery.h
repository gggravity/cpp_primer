#pragma once
//
// Created by martin on 04-06-22.
//

#include <bits/stdc++.h>
#include "QueryBase.h"
#include "Query.h"

using namespace std;

class BinaryQuery : public QueryBase
   {
   protected:
      BinaryQuery (Query lhs, Query rhs, string s);

      [[nodiscard]] string rep () const override;

      Query lhs;
      Query rhs;
      string op_sym;

   };
