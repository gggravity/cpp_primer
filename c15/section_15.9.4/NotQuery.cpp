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
  auto results = query.eval (text_query);

  auto ret_lines = make_shared<set<size_t>>();

  auto begin = results.begin();
  auto end = results.end();

  auto size = results.get_file()->size();

  for (size_t n {0}; n != size; ++n)
    {
      if (begin == end || *begin != n)
        {
          ret_lines->insert (n);
        }
      else if (begin != end)
        {
          ++begin;
        }
    }

  return {rep(), ret_lines, results.get_file()};
}

Query operator~(const Query &query)
{
  cout << "NotQuery operator running..." << endl;
  return shared_ptr<QueryBase> (new NotQuery (query));
}
