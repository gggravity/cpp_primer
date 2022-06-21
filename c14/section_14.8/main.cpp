#include <bits/stdc++.h>

using namespace std;

struct if_then_else
{
  string operator() (bool test, const string &s1, const string &s2) { return test ? s1 : s2; }
};

struct PrintString
{
  string operator() (istream &is)
  {
    string s;
    getline (is, s);
    if (is.bad())
      {
        cerr << "istream input error" << endl;
        return {};
      }
    return s;
  }
};

class Equal
{
public:

  explicit Equal (string old_value) : old_value (std::move (old_value)) {}

  bool operator() (const string &test_string) { return test_string == old_value; }

private:

  string old_value;
};

int main()
try
  {
    //    if_then_else tester;
    //    cout << tester(1 == 2, "correct", "wrong") << endl;
    //    cout << tester(1 == 1, "correct", "wrong") << endl;
    //    cout << tester(1 != 2, "correct", "wrong") << endl;
    //
    //    istringstream iss { "Testing string....." };
    //    PrintString print_string;
    //
    //    cout << print_string(iss) << endl;
    //
    //    vector<string> v;
    //
    //    cout << "enter some line of text: ";
    //
    //    while (!cin.eof())
    //      {
    //        v.emplace_back(print_string(cin));
    //      }
    //
    //    for (auto &line : v)
    //      {
    //        cout << line << endl;
    //      }

    vector<string> v {"A", "B", "C"};

    replace_if (v.begin(), v.end(), Equal ("A"), "ananas");
    replace_if (v.begin(), v.end(), Equal ("B"), "banana");
    replace_if (v.begin(), v.end(), Equal ("C"), "cocktail");

    for (auto &s : v)
      {
        cout << s << " ";
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
