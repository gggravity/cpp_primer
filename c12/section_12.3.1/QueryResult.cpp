//
// Created by martin on 25/05/2022.
//

#include "QueryResult.h"

QueryResult::QueryResult (const shared_ptr<map<string, set<int>>> &word_to_lines)
    : word_to_lines(word_to_lines)
  {

  }
