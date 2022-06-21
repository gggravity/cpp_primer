//
// Created by martin on 25-05-22.
//
#pragma once

#include "string_vector.h"
#include <bits/stdc++.h>

using namespace std;

class QueryResult
{
  using line_no = size_t;
  friend ostream &print (ostream &os, const QueryResult &query_result);

public:

  QueryResult (string s, shared_ptr<set<line_no>> p, const shared_ptr<string_vector> &f);

  set<line_no>::iterator begin();
  set<line_no>::iterator end();

  shared_ptr<string_vector> get_file();

private:

  string sought;
  shared_ptr<set<line_no>> lines;
  shared_ptr<string_vector> file;
};
