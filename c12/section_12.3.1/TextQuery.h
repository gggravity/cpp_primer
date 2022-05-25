#pragma once

#include <bits/stdc++.h>
#include "QueryResult.h"

using namespace std;

class TextQuery
      {
            typedef map<string, set<int>> word_map;

      public:
            explicit TextQuery (ifstream &infile);

            QueryResult query (const string& s);

      private:
            shared_ptr<vector<string>> lines;
            shared_ptr<word_map> word_to_lines;
      };
