//
// Created by martin on 04-06-22.
//

#include "AndQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"

AndQuery::AndQuery (const Query &lhs, const Query &rhs) :
    BinaryQuery(lhs, rhs, "&")
  {

  }

QueryResult AndQuery::eval (const TextQuery &text_query) const
  {
    cout << "AndQuery eval operator running..." << endl;
    auto left = lhs.eval(text_query);
    auto right = rhs.eval(text_query);

    auto ret_lines = make_shared<set<size_t>>();

    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));

    return { rep(), ret_lines, left.get_file() };
  }

Query operator& (const Query &lhs, const Query &rhs)
  {
    cout << "AndQuery operator running..." << endl;
    return shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
  }