//
// Created by martin on 04-06-22.
//

#include "OrQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"

OrQuery::OrQuery (const Query &lhs, const Query &rhs) : BinaryQuery (lhs, rhs, "|") {}

QueryResult OrQuery::eval (const TextQuery &text_query) const
{
  cout << "OrQuery eval running..." << endl;
  return {};
}

Query operator| (const Query &lhs, const Query &rhs)
{
  cout << "OrQuery running..." << endl;
  return shared_ptr<QueryBase> (new OrQuery (lhs, rhs));
}
