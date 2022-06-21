#include "Sales_data.h"
#include <bits/stdc++.h>

using namespace std;

bool five_or_more (const string &string) { return string.size() >= 5; }

bool compare_isbn (const Sales_data &sd1, const Sales_data &sd2) { return sd1.isbn() < sd2.isbn(); }

void print (vector<string> &v, const string &title)
{
  cout << title << ": ";
  for (auto &item : v)
    {
      cout << item << " ";
    }
  cout << endl;
}

bool is_shorter (const string &s1, const string &s2) { return s1.size() < s2.size(); }

void eliminate_duplicates (vector<string> &words)
{
  sort (words.begin(), words.end());
  print (words, "sorted");
  auto end_unique {unique (words.begin(), words.end())};
  words.erase (end_unique, words.end());
}

int main (int argc, char *argv[])
try
  {
    string s {"the quick red fox jumps over the slow red turtle"};
    istringstream iss {s};
    vector<string> vs;

    for (string word; iss >> word;)
      {
        vs.push_back (word);
      }

    print (vs, "vs");
    eliminate_duplicates (vs);
    print (vs, "dup_removed");

    stable_sort (vs.begin(), vs.end(), is_shorter);
    print (vs, "stable_sorted");

    vector<Sales_data> vsd;
    for (int i {0}; i < 10; ++i)
      {
        vsd.emplace_back ("book " + to_string (rand() % 100));
      }

    for (auto &sd : vsd)
      {
        print (cout, sd);
        cout << endl;
      }

    cout << "----------" << endl;

    sort (vsd.begin(), vsd.end(), compare_isbn);

    for (auto &sd : vsd)
      {
        print (cout, sd);
        cout << endl;
      }

    string words {
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed id nibh velit. Fusce varius urna tortor, eu blandit dolor ornare ut. Mauris vel aliquam nunc. Vestibulum semper cursus semper. Donec volutpat diam ut metus accumsan auctor. Aenean vulputate dignissim diam vel ullamcorper. Quisque vel euismod ipsum. Suspendisse et quam pharetra, fringilla velit vel, malesuada erat. Pellentesque dictum facilisis cursus. Curabitur risus dolor, suscipit quis sapien vitae, blandit finibus orci. Morbi feugiat facilisis mi tincidunt tincidunt. Donec fermentum purus quis velit aliquet posuere. Nulla molestie risus a eros tincidunt, quis mattis quam consequat. Donec non nisi sollicitudin est suscipit varius. Nunc dictum justo massa, eu interdum elit mollis vitae. Suspendisse molestie lobortis dapibus."};
    istringstream iss2 {words};

    vector<string> string_vector;
    for (string word; iss2 >> word;)
      {
        string_vector.push_back (word);
      }

    print (string_vector, "string_vector");
    cout << "----------" << endl;
    auto end_iter {partition (string_vector.begin(), string_vector.end(), five_or_more)};

    string_vector.erase (end_iter, string_vector.end());  // non alpha not removed.
    print (string_vector, "string_vector (five or more)");

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
