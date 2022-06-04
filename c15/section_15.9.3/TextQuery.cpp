//
// Created by martin on 25-05-22.
//

#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery (ifstream &ifs)
    : file(new vector<string>)
  {
    string text;

    while (getline(ifs, text))
      {
        file->push_back(text);
        int n = int(file->size() - 1);
        istringstream line { text };
        string word;

        while (line >> word)
          {
            auto &lines = wm[word];

            if (!lines)
              {
                lines.reset(new set<line_no>);
              }
            lines->insert(n);
          }
      }
  }

QueryResult TextQuery::query (const string &query) const
  {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(query);

    if (loc == wm.end())
      {
        return { query, nodata, file };
      }
    else
      {
        return { query, loc->second, file };
      }
  }
