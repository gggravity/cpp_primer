#pragma once

#include "QueryResult.h"
#include <bits/stdc++.h>

using namespace std;

class TextQuery
{
  typedef map<string, set<int>> word_map;

public:

  [[maybe_unused]] explicit TextQuery (ifstream &infile);

  QueryResult query (const string &s);

private:

  shared_ptr<vector<string>> lines;
  shared_ptr<word_map> word_to_lines;
};
