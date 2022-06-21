//
// Created by martin on 25-05-22.
//
#pragma once

#include <bits/stdc++.h>

using namespace std;

class QueryResult
{
  friend ostream &print (ostream &os, const QueryResult &query_result);

public:

  QueryResult() = default;

  QueryResult (string sought, shared_ptr<set<size_t>> ptr, const shared_ptr<vector<string>> &file);

  set<size_t>::iterator begin();

  set<size_t>::iterator end();

  shared_ptr<vector<string>> get_file();

private:

  string sought;
  shared_ptr<set<size_t>> lines;
  shared_ptr<vector<string>> file;
};
