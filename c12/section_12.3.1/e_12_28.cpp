//
// Created by martin on 25-05-22.
//
#include <bits/stdc++.h>

using namespace std;

typedef map<string, set<int>> word_map;

ostream &print (ostream &os, const string &query, vector<string> lines, word_map word_to_lines)
{
  auto pos {word_to_lines.find (query)};

  size_t times;

  if (pos != word_to_lines.end())
    {
      times = pos->second.size();
    }
  else
    {
      times = 0;
    }

  os << query << " occurs " << times << " times" << endl;

  for (auto &elem : pos->second)
    {
      cout << "(line " << elem << ") " << lines.at (elem) << endl;
    }
  return os;
}

void runQueries (ifstream &infile)
{
  word_map word_to_lines;
  vector<string> lines;

  for (string line; getline (infile, line);)
    {
      lines.push_back (line);
    }

  string word;
  for (int i {0}; i < lines.size(); ++i)
    {
      istringstream iss {lines[i]};
      while (iss >> word)
        {
          word_to_lines[word].insert (i);
        }
    }

  //    while (true)
  //      {
  //        cout << "enter word to look for, or q to quit: ";
  //        string s;
  //
  //        if (!( cin >> s ) || s == "q")
  //          {
  //            break;
  //          }
  //
  //        print(cout, s, lines, word_to_lines) << endl;
  //      }

  do
    {
      cout << "enter word to look for, or q to quit: ";
      string s;

      if (! (cin >> s) || s == "q")
        {
          break;
        }

      print (cout, s, lines, word_to_lines) << endl;
    }
  while (true);
}

int main()
try
  {
    ifstream ifs {"../text.txt"};
    runQueries (ifs);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
