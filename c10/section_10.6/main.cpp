#include <bits/stdc++.h>

using namespace std;

void print (list<string> &list, const string& title)
  {
    cout << title << ": ";
    for (auto &item : list)
      {
        cout << item << " ";
      }
    cout << endl;
  }

int main ()
try
  {
    string s { "the quick red fox jumps over the slow red turtle" };
    istringstream iss { s };
    list<string> ls;

    for (string word ; iss >> word ;)
      {
        ls.push_back(word);
      }

    print(ls, "list string");
    ls.sort();
    print(ls, "list sorted");
    ls.unique();
    print(ls, "dup removed");

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


