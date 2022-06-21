//
// Created by martin on 03-06-22.
//

#include "Query.h"
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

Query::Query (const string &q) {}

QueryResult Query::eval (const TextQuery &text_query) const { return q->eval (text_query); }

string Query::rep() const { return q->rep(); }

Query::Query (shared_ptr<QueryBase> query) : q (std::move (query)) {}

ostream &operator<< (ostream &os, const Query &query)
{
  os << query.rep();
  return os;
}
