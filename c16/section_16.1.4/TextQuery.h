#pragma once

#include <bits/stdc++.h>
#include "QueryResult.h"
#include "DebugDelete.h"

using namespace std;

class TextQuery
   {
      typedef map<string, set<int>> word_map;

   public:
      explicit TextQuery (ifstream &infile)
        {
          word_to_lines = shared_ptr<word_map> { new word_map, DebugDelete() };
          lines = shared_ptr<vector<string>> { new vector<string>, DebugDelete() };

          for (string line ; getline(infile, line) ;)
            {
              lines->push_back(line);
            }

          string word;

          for (int i { 0 } ; i < lines->size() ; ++i)
            {
              istringstream iss { ( *lines )[i] };
              while (iss >> word)
                {
                  ( *word_to_lines )[word].insert(i);
                }
            }
/*
    for (auto &item : *word_to_lines)
      {
        cout << item.first << ": ";
        for (auto &line_no : item.second)
          {
            cout << line_no << " ";
          }
        cout << endl;
*/
        }

      QueryResult query (const string &s)
        {
          return { s, lines, word_to_lines };
        }

   private:
      shared_ptr<vector<string>> lines;
      shared_ptr<word_map> word_to_lines;
   };

ostream &print (ostream &os, const QueryResult &qr)
  {
    auto pos { qr.word_to_lines->find(qr.query) };

    size_t times;

    if (pos != qr.word_to_lines->end())
      {
        times = pos->second.size();
      }
    else
      {
        times = 0;
      }

    os << qr.query << " occurs " << times << " times" << endl;

    for (auto &elem : pos->second)
      {
        cout << "(line " << elem << ") " << qr.lines->at(elem) << endl;
      }
    return os;
  }

void runQueries (ifstream &infile)
  {
    TextQuery tq(infile);

    while (true)
      {
        cout << "enter word to look for, or q to quit: ";
        string s;

        if (!( cin >> s ) || s == "q")
          {
            break;
          }

        print(cout, tq.query(s)) << endl;
      }
  }
