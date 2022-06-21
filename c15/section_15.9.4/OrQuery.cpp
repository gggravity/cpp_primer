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
  auto right = rhs.eval (text_query);
  auto left = lhs.eval (text_query);

  auto ret_lines {make_shared<set<size_t>> (left.begin(), left.end())};
  ret_lines->insert (right.begin(), right.end());
  return {rep(), ret_lines, left.get_file()};
}

Query operator| (const Query &lhs, const Query &rhs)
{
  cout << "OrQuery running..." << endl;
  return shared_ptr<QueryBase> (new OrQuery (lhs, rhs));
}
