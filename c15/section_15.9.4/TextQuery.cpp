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
            auto &lines = word_map[word];

            if (!lines)
              {
                lines.reset(new set<size_t>);
              }
            lines->insert(n);
          }
      }
  }

QueryResult TextQuery::query (const string &query) const
  {
    static shared_ptr<set<size_t>> no_data(new set<size_t>);

    auto loc = word_map.find(query);

    if (loc == word_map.end())
      {
        return { query, no_data, file };
      }
    else
      {
        return { query, loc->second, file };
      }
  }
