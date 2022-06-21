#include <bits/stdc++.h>

using namespace std;

auto random_choice()
{
  seed_seq seed = {time (nullptr)};
  default_random_engine engine (seed);
  bernoulli_distribution distribution;

  return distribution (engine);
}

map<string, string> buildMap (ifstream &map_file)
{
  map<string, string> trans_map;
  string key;
  string value;

  while (map_file >> key && getline (map_file, value))
    {
      if (value.size() > 1)
        {
          trans_map[key] = value.substr (1);
        }
      else
        {
          throw runtime_error ("no rules for " + key);
        }
    }
  return trans_map;
}

const string &transform (const string &s, const map<string, string> &m)
{
  auto map_it = m.find (s);

  if (map_it != m.cend())
    {
      return map_it->second;
    }
  else
    {
      return s;
    }
}

void word_transform (ifstream &input)
{
  ifstream map_file;

  if (random_choice())
    {
      map_file.open ("../map_file_1.txt");
    }
  else
    {
      map_file.open ("../map_file_2.txt");
    }

  auto trans_map = buildMap (map_file);

  string text;

  while (getline (input, text))
    {
      istringstream stream {text};
      string word;
      bool first_word {true};
      while (stream >> word)
        {
          if (first_word)
            {
              first_word = false;
            }
          else
            {
              cout << " ";
            }
          cout << transform (word, trans_map);
        }
      cout << endl;
    }
}

int main()
try
  {
    ifstream input {"../input.txt"};

    word_transform (input);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
