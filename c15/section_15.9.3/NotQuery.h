#pragma once
//
// Created by martin on 04-06-22.
//

class TextQuery;

class QueryResult;

#include "Query.h"
#include "QueryBase.h"
#include <bits/stdc++.h>

using namespace std;

class NotQuery : public QueryBase
{
  friend Query operator~(const Query &query);

  NotQuery (Query query);

  [[nodiscard]] string rep() const override;

  [[nodiscard]] QueryResult eval (const TextQuery &text_query) const override;

  Query query;
};