#include <bits/stdc++.h>

using namespace std;

class test_bound
{
public:

  test_bound (size_t lower, size_t upper) : lower (lower), upper (upper) {}

  bool operator() (const string &string) const { return string.size() >= lower && string.size() <= upper; }

private:

  size_t lower;
  size_t upper;
};

class larger_then
{
public:

  explicit larger_then (size_t size) : larger (size) {}

  bool operator() (const string &string) const { return string.size() >= larger; }

private:

  size_t larger;
};

struct print_string
{
  void operator() (const string &word) const { cout << word << endl; }
};

struct less_then
{
  bool operator() (const string &a, const string &b) const { return a.size() < b.size(); }
};

void eliminate_dups (vector<string> &words)
{
  sort (words.begin(), words.end());
  auto end_unique = unique (words.begin(), words.end());
  words.erase (end_unique, words.end());
}

void biggies (vector<string> &words, size_t sz)
{
  eliminate_dups (words);

  stable_sort (words.begin(), words.end(), less_then());

  auto wc = find_if (words.begin(), words.end(), larger_then (sz));

  auto count = words.end() - wc;

  for_each (wc, words.end(), print_string());

  cout << count << (count > 1 ? " unique words" : " unique word") << " of length " << sz << " or longer" << endl;

  cout << endl;
}

int main()
try
  {
    ifstream ifs {"CMakeCache.txt"};

    if (! ifs)
      {
        cerr << "can't open file" << endl;
        exit (EXIT_FAILURE);
      }

    vector<string> v;
    for (string word; ifs >> word;)
      {
        v.emplace_back (word);
      }

    cout << v.size() << endl;

    biggies (v, 1);

    //    int counter_bound { 0 };
    //    int lower { 1 };
    //    int upper { 10 };
    //
    //    for (auto iter { v.begin() }, new_iter { iter } ; iter <= v.end() ; ++iter)
    //      {
    //        new_iter = find_if(iter, v.end(), test_length(lower, upper));
    //
    //        if (new_iter != iter)
    //          {
    //            counter_bound++;
    //            iter = new_iter;
    //          }
    //      }
    //
    //    cout << "words between " << lower << " and " << upper << ": " << counter_bound << endl;

    size_t counter_bound {0};
    size_t lower {1};
    size_t upper {10};

    ifs.clear();
    ifs.seekg (0);
    istream_iterator<string> iter (ifs), eof;

    counter_bound = count_if (iter, eof, test_bound (lower, upper));

    cout << "words between " << lower << " and " << upper << " (inclusive): " << counter_bound << endl;

    size_t counter_larger {0};
    size_t larger {10};

    ifs.clear();
    ifs.seekg (0);
    counter_larger = count_if (iter, eof, larger_then (larger));

    cout << "words larger then " << larger << ": " << counter_larger << endl;

    cout << "words in total: " << v.size() << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
