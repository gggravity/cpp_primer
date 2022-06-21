//
// Created by martin on 25/05/2022.
//

#include "QueryResult.h"

QueryResult::QueryResult (string query, const shared_ptr<vector<string>> &lines,
                          const shared_ptr<word_map> &word_to_lines)
    : query (move (query)), lines (lines), word_to_lines (word_to_lines)
{
}
