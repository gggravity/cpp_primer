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
      TextQuery (ifstream &ifs);

      [[nodiscard]] QueryResult query (const string &query) const;

   private:
      shared_ptr<vector<string>> file;

      map<string, shared_ptr<set<size_t>>> word_map;

   };
