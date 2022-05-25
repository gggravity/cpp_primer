//
// Created by martin on 25/05/2022.
//

#include "TextQuery.h"
//#include "QueryResult.h"

TextQuery::TextQuery (ifstream &infile)
  {
    word_to_lines = make_shared<word_map>();
    lines = make_shared<vector<string>>();

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

//    for (auto &item : *word_to_lines)
//      {
//        cout << item.first << ": ";
//        for (auto &line_no : item.second)
//          {
//            cout << line_no << " ";
//          }
//        cout << endl;

  }

QueryResult TextQuery::query (const string& s)
  {
    return { s, lines, word_to_lines };
  }
