#pragma once
//
// Created by martin on 03-06-22.
//
#include <bits/stdc++.h>

class TextQuery;
class QueryResult;
class QueryBase;

using namespace std;

class Query
   {
      friend Query operator~ (const Query &query);

      friend Query operator| (const Query &lhs, const Query &rhs);

      friend Query operator& (const Query &lhs, const Query &rhs);

   public:
      Query (const string &q);

      [[nodiscard]] QueryResult eval (const TextQuery &text_query) const;

      [[nodiscard]] string rep () const;

      friend ostream &operator<< (ostream &os, const Query &query);

   private:
      Query (shared_ptr<QueryBase> query);

      shared_ptr<QueryBase> q;
   };
