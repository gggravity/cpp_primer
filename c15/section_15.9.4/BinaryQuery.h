#pragma once
//
// Created by martin on 04-06-22.
//

#include "Query.h"
#include "QueryBase.h"
#include <bits/stdc++.h>

using namespace std;

class BinaryQuery : public QueryBase
{
protected:

  BinaryQuery (Query lhs, Query rhs, string str);

  [[nodiscard]] string rep() const override;

  Query lhs;
  Query rhs;
  string operator_symbol;
};
