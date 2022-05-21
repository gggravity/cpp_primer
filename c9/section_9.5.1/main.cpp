#include <bits/stdc++.h>

using namespace std;

string vector_char_to_string (vector<char> vc)
  {
    string s;

    for (auto &c : vc)
      {
        s.push_back(c);
      }

    return s;
  }

int main (int argc, char *argv[])
try
  {
    vector<char> vc { 'a', 'b', 'c' };

    auto s = vector_char_to_string(vc);

    cout << s << endl;

    string s100;
    s100.reserve(100);
    cout << s100.capacity() << endl;
    
    for (int i { 33 } ; i < 133 ; ++i)
      {
        if (i >= 127)
          {
            s100.push_back(char(33));
          }
        else
          {
            s100.push_back(char(i));
          }
      }

    cout << s100 << endl;
    cout << s100.capacity();

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


