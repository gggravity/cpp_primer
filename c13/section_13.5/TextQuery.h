//
// Created by martin on 25-05-22.
//
#pragma once

#include <bits/stdc++.h>
#include "string_vector.h"

using namespace std;

class QueryResult;

class TextQuery
      {
      public:
            using line_no = size_t;

            TextQuery (ifstream &ifs);

            QueryResult query (const string &query) const;

      private:
            shared_ptr<string_vector> file;

            map<string, shared_ptr<set<line_no>>> wm;

      };
