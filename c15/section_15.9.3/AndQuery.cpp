//
// Created by martin on 04-06-22.
//

#include "AndQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"

AndQuery::AndQuery (const Query &lhs, const Query &rhs) : BinaryQuery (lhs, rhs, "&") {}

QueryResult AndQuery::eval (const TextQuery &text_query) const
{
  cout << "AndQuery eval operator running..." << endl;
  return {};
}

Query operator& (const Query &lhs, const Query &rhs)
{
  cout << "AndQuery operator running..." << endl;
  return shared_ptr<QueryBase> (new AndQuery (lhs, rhs));
}