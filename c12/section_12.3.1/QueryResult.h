#pragma once

#include <bits/stdc++.h>

using namespace std;

class QueryResult
{
  typedef map<string, set<int>> word_map;

public:

  QueryResult (string query, const shared_ptr<vector<string>> &lines, const shared_ptr<word_map> &word_to_lines);

  string query;
  shared_ptr<vector<string>> lines;
  shared_ptr<word_map> word_to_lines;
};