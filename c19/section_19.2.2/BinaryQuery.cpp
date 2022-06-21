//
// Created by martin on 04-06-22.
//

#include "BinaryQuery.h"

#include <utility>

BinaryQuery::BinaryQuery (Query lhs, Query rhs, string s)
    : lhs (std::move (lhs)), rhs (std::move (rhs)), op_sym (std::move (s))
{
}

string BinaryQuery::rep() const
{
  cout << "BinaryQuery rep running..." << endl;
  return "(" + lhs.rep() + " " + op_sym + " " + rhs.rep() + ")";
}
