#include <bits/stdc++.h>
#include <ostream>

// NOT WORKING !!!

using namespace std;

int main (int argc, char *argv[])
try
  {
    stack<char> s;

    string expression {"(2*2)"};

    for (auto &c : expression)
      {
        s.push(c);
      }


    bool seen { false };

    while (!s.empty())
      {
        auto top = s.top();
        cout << top;
//        if (top == "(")
//          {
//            seen = true;
//          }
        s.pop();
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


