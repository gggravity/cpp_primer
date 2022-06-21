#pragma once
//
// Created by martin on 04-06-22.
//

class TextQuery;

class QueryResult;

#include "BinaryQuery.h"
#include <bits/stdc++.h>

using namespace std;

class OrQuery : public BinaryQuery
{
public:

  friend Query operator| (const Query &lhs, const Query &rhs);

  OrQuery (const Query &lhs, const Query &rhs);

  [[nodiscard]] QueryResult eval (const TextQuery &text_query) const;
};
