//
// Created by martin on 25-05-22.
//
#pragma once

#include <bits/stdc++.h>

using namespace std;

class QueryResult
{
  using line_no = vector<string>::size_type;
  friend ostream &print (ostream &os, const QueryResult &query_result);

public:

  QueryResult (string s, shared_ptr<set<line_no>> p, const shared_ptr<vector<string>> &f);

  set<line_no>::iterator begin();
  set<line_no>::iterator end();

  shared_ptr<vector<string>> get_file();

private:

  string sought;
  shared_ptr<set<line_no>> lines;
  shared_ptr<vector<string>> file;
};
