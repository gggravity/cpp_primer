#pragma once

#include <bits/stdc++.h>

using namespace std;

class QueryResult
      {
      public:
            QueryResult (const shared_ptr<map<string, set<int>>> &word_to_lines);

      public:

      private:
            shared_ptr<map<string, set<int>>> word_to_lines;

      };
