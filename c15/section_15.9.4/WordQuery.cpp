//
// Created by martin on 04-06-22.
//

#include "WordQuery.h"

WordQuery::WordQuery (string s) :
    query_word(std::move(s))
  {

  }

QueryResult WordQuery::eval (const TextQuery &text_query) const
  {
    return text_query.query(query_word);
  }


string WordQuery::rep () const
  {
    return query_word;
  }
