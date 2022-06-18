//
// Created by martin on 25-05-22.
//
#pragma once

#include <bits/stdc++.h>

using namespace std;

//class QueryResult;

class TextQuery
   {
   public:

      class QueryResult
         {
            using line_no = vector<string>::size_type;

            friend ostream &print (ostream &os, const QueryResult &query_result);

         public:
            QueryResult () = default;

            QueryResult (string s, shared_ptr<set<line_no>> p, const shared_ptr<vector<string>> &f)
                :
                sought(move(s)),
                lines(move(p)),
                file(f)
              {

              }

            set<line_no>::iterator begin ()
              {
                return lines->begin();
              }

            set<line_no>::iterator end ()
              {
                return lines->end();
              }

            shared_ptr<vector<string>> get_file ()
              {
                return file;
              }

         private:
            string sought;
            shared_ptr<set<line_no>> lines;
            shared_ptr<vector<string>> file;
         };

      using line_no = vector<string>::size_type;

      TextQuery (ifstream &ifs);

      TextQuery::QueryResult query (const string &query) const;

   private:
      shared_ptr<vector<string>> file;

      map<string, shared_ptr<set<line_no>>> wm;

   };
