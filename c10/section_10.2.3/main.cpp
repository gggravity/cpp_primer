#include <bits/stdc++.h>

using namespace std;

void print (vector<string> &v, const string& title)
  {
    cout << title << ": ";
    for (auto &item : v)
      {
        cout << item << " ";
      }
    cout << endl;
  }

void eliminate_duplicates (vector<string> &words)
  {
    sort(words.begin(), words.end());
    print(words, "sorted");
    auto end_unique { unique(words.begin(), words.end()) };
    words.erase(end_unique, words.end());
  }

int main (int argc, char *argv[])
try
  {
    string s { "the quick red fox jumps over the slow red turtle" };
    istringstream iss { s };
    vector<string> vs;

    for (string word ; iss >> word ;)
      {
        vs.push_back(word);
      }

    print(vs, "vs");
    eliminate_duplicates(vs);
    print(vs, "dup_removed");

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


