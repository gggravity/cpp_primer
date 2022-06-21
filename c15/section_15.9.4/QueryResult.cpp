//
// Created by martin on 25-05-22.
//

#include "QueryResult.h"

using line_no = vector<string>::size_type;

QueryResult::QueryResult (string sought, shared_ptr<set<size_t>> ptr, const shared_ptr<vector<string>> &file)
    : sought (move (sought)), lines (move (ptr)), file (file)
{
}

set<line_no>::iterator QueryResult::begin() { return lines->begin(); }

set<line_no>::iterator QueryResult::end() { return lines->end(); }

shared_ptr<vector<string>> QueryResult::get_file() { return file; }
