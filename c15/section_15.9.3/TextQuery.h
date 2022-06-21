//
// Created by martin on 25-05-22.
//
#pragma once

#include <bits/stdc++.h>

using namespace std;

class QueryResult;

class TextQuery
{
public:

  using line_no = vector<string>::size_type;

  TextQuery (ifstream &ifs);

  QueryResult query (const string &query) const;

private:

  shared_ptr<vector<string>> file;

  map<string, shared_ptr<set<line_no>>> wm;
};
