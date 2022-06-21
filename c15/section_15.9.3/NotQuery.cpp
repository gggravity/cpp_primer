//
// Created by martin on 04-06-22.
//

#include "NotQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"

NotQuery::NotQuery (Query query) : query (std::move (query)) {}

string NotQuery::rep() const
{
  cout << "NotQuery rep running..." << endl;
  return "~(" + query.rep() + ")";
}

QueryResult NotQuery::eval (const TextQuery &text_query) const
{
  cout << "NotQuery eval running..." << endl;
  return {};
}

Query operator~(const Query &query)
{
  cout << "NotQuery operator running..." << endl;
  return shared_ptr<QueryBase> (new NotQuery (query));
}
