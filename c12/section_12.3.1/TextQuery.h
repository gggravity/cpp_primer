#pragma once

#include <bits/stdc++.h>
#include "QueryResult.h"

using namespace std;

class TextQuery
      {
      public:
            explicit TextQuery (ifstream &infile);

            QueryResult query (string s);

      private:
            vector<string> lines;
            shared_ptr<map<string,set<int>>> word_to_lines;
      };
