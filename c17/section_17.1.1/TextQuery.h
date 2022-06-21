#pragma once

#include <bits/stdc++.h>

using namespace std;

typedef map<string, set<int>> word_map;
typedef tuple<string, const shared_ptr<vector<string>>, const shared_ptr<word_map>> QueryResult;

class TextQuery
{
public:

  explicit TextQuery (ifstream &infile)
  {
    word_to_lines = make_shared<word_map>();
    lines = make_shared<vector<string>>();

    for (string line; getline (infile, line);)
      {
        lines->push_back (line);
      }

    string word;

    for (int i {0}; i < lines->size(); ++i)
      {
        istringstream iss {(*lines)[i]};
        while (iss >> word)
          {
            (*word_to_lines)[word].insert (i);
          }
      }
  }

  QueryResult query (const string &s) { return {s, lines, word_to_lines}; }

private:

  shared_ptr<vector<string>> lines;
  shared_ptr<word_map> word_to_lines;
};

ostream &print (ostream &os, const QueryResult &qr)
{

  auto pos {get<2> (qr)->find (get<0> (qr))};

  size_t times;

  if (pos != get<2> (qr)->end())
    {
      times = pos->second.size();
    }
  else
    {
      times = 0;
    }

  os << get<0> (qr) << " occurs " << times << " times" << endl;

  for (auto &elem : pos->second)
    {
      cout << "(line " << elem << ") " << get<1> (qr)->at (elem) << endl;
    }
  return os;
}

void runQueries (ifstream &infile)
{
  if (! infile)
    {
      cerr << "Can't open input file" << endl;
      exit (EXIT_FAILURE);
    }

  TextQuery tq (infile);

  while (true)
    {
      cout << "enter word to look for, or q to quit: ";
      string s;

      if (! (cin >> s) || s == "q")
        {
          break;
        }

      print (cout, tq.query (s)) << endl;
    }
}
