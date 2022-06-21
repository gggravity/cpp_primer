#include <bits/stdc++.h>

using namespace std;
using namespace std::placeholders;

bool check_size (const string &s, vector<string>::size_type sz) { return s.size() > sz; }

void eliminate_dups (vector<string> &words)
{
  sort (words.begin(), words.end());
  auto end_iter {unique (words.begin(), words.end())};
  words.erase (end_iter, words.end());
}

int main (int argc, char *argv[])
try
  {
    // e 10.22
    vector<string> words {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    vector<string>::size_type sz {4};

    auto count = count_if (words.begin(), words.end(), bind (check_size, _1, sz));

    cout << count << " are larger then " << sz << " characters." << endl;

    // e 10.24
    cout << "-------" << endl;

    vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto iter = find_if_not (vi.begin(), vi.end(), bind (check_size, "test", _1));

    cout << *iter << endl;

    // e 10.25

    auto biggies = [&words, sz]() {
      eliminate_dups (words);
      stable_sort (words.begin(), words.end(), [] (const string &a, const string &b) { return a.size() < b.size(); });

      //          auto end_iter = partition(words.begin(), words.end(), [sz] (const string &a)
      //            {
      //                return a.size() >= sz;
      //            });

      auto end_iter = partition (words.begin(), words.end(), bind (check_size, _1, sz));

      auto count {distance (words.begin(), end_iter)};

      cout << "There are " << count << " " << (count > 1 ? "words" : "word") << " longer than " << sz
           << " letters, they are: ";

      for_each (words.begin(), end_iter, [] (const string &s) { cout << s << " "; });
      cout << endl;
    };

    biggies();

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
