#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
    list<const char *> list_c_style_string;
    list_c_style_string.push_back("Element 1");
    list_c_style_string.push_back("Element 2");
    list_c_style_string.push_back("Element 3");
    list_c_style_string.push_back("Element 4");
    list_c_style_string.push_back("Element 5");
    list_c_style_string.push_back("Element 6");

    for (auto &s : list_c_style_string)
      {
        cout << s << endl;
      }

    cout << "---------------------------" << endl;

    vector<string> vs { list_c_style_string.begin(), list_c_style_string.end() };

    for (auto &s : vs)
      {
        cout << s << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }














