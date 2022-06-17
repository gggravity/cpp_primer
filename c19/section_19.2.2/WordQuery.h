#pragma once
//
// Created by martin on 04-06-22.
//
#include <bits/stdc++.h>
#include "QueryBase.h"
#include "QueryResult.h"

using namespace std;

class WordQuery : public QueryBase
   {
      friend class Query;

      WordQuery (string s);

      [[nodiscard]] QueryResult eval(const TextQuery &text_query) const override;

      [[nodiscard]] string rep() const override;

      string query_word;

   };
