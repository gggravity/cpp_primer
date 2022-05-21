#include <bits/stdc++.h>

using namespace std;

void string_manipulation_iterator (string &s, const string &oldVal, const string &newVal)
  {
    for (auto iter { s.begin() } ; iter < s.end() ; ++iter)
      {
        if (*iter == oldVal.front())
          {
            for (int i { 1 } ; i != oldVal.size() ; ++i)
              {
                if (*( iter + i ) != oldVal.at(i))
                  {
                    break;
                  }
                if (i + 1 == oldVal.size())
                  {
                    auto pos = distance(s.begin(), iter);
                    s.erase(pos, oldVal.size());
                    s.insert(pos, newVal);
                    iter = s.begin() + pos + int(newVal.size());
                  }
              }
          }
      }
  }

void string_manipulation_index_and_replace (string &s, const string &oldVal, const string &newVal)
  {
    for (int i { 0 } ; i < s.size() ; ++i)
      {
        if (s.at(i) == oldVal.at(0))
          {
            for (int j { 1 } ; j != oldVal.size() ; ++j)
              {
                if (s.at(i + j) != oldVal.at(j))
                  {
                    break;
                  }
                if (j + 1 == oldVal.size())
                  {
                    s.replace(i, oldVal.size(), newVal);
                  }
              }
          }
      }
  }

string &prefix_and_suffix (string &name, const string& prefix, const string& suffix)
  {
    name.insert(0, prefix);
//    name.append(suffix);
    name.insert(distance(name.begin(), name.end()), suffix);
    return name;
  }

int main (int argc, char *argv[])
try
  {
    string s { "there was tho tho and thru" };

    cout << s << endl;
    string_manipulation_iterator(s, "tho", "though");
    cout << s << endl;
    string_manipulation_iterator(s, "thru", "through");
    cout << s << endl;

    cout << "---------------------" << endl;

    s = "there was tho tho and thru";

    cout << s << endl;
    string_manipulation_index_and_replace(s, "tho", "though");
    cout << s << endl;
    string_manipulation_index_and_replace(s, "thru", "through");
    cout << s << endl;

    cout << "---------------------" << endl;

    string s1 = "Anna";
    cout << prefix_and_suffix(s1, "Ms. ", ", The III Queen of Mars.");

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


