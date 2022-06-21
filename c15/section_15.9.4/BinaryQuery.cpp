//
// Created by martin on 04-06-22.
//

#include "BinaryQuery.h"

#include <utility>

BinaryQuery::BinaryQuery (Query lhs, Query rhs, string str)
    : lhs (std::move (lhs)), rhs (std::move (rhs)), operator_symbol (std::move (str))
{
}

string BinaryQuery::rep() const
{
  cout << "BinaryQuery rep running..." << endl;
  return "(" + lhs.rep() + " " + operator_symbol + " " + rhs.rep() + ")";
}
