//
// Created by martin on 25-05-22.
//

#include "QueryResult.h"

using line_no = vector<string>::size_type;

QueryResult::QueryResult (string s, shared_ptr<set<line_no>> p, const shared_ptr<string_vector> &f)
    : sought (move (s)), lines (move (p)), file (f)
{
}

set<line_no>::iterator QueryResult::begin() { return lines->begin(); }

set<line_no>::iterator QueryResult::end() { return lines->end(); }

shared_ptr<string_vector> QueryResult::get_file() { return file; }
