#include <bits/stdc++.h>
#include "String.h"
#include "string_vector.h"
#include "message.h"

using namespace std;

string_vector string_vector_factory (size_t n = 10)
  {
    string_vector sv;

    for (size_t i { 0 } ; i < n ; ++i)
      {
        sv.push_back(to_string(i));
      }
    return std::move(sv);
  }

String string_factory (size_t n = 10)
  {
    String s;

    for (size_t i { 0 } ; i < n ; ++i)
      {
        s.push_back(char(i + 48));
      }
    return std::move(s);
  }

message message_factory (size_t start = 48, size_t n = 10)
  {
    string s;

    for (size_t i { 0 } ; i < n ; ++i)
      {
        s.push_back(char(i + start));
      }

    message m { s };

    return std::move(m);
  }

int main ()
try
  {
    // e 13.49
    auto sv1 = string_vector_factory();

    string_vector sv2;
    sv2 = string_vector { "one", "two", "three" };

    cout << sv1 << endl;
    cout << sv2 << endl;

    auto s1 = string_factory();

    String s2;
    s2 = String { 'A', 'B', 'C' };

    cout << s1 << endl;
    cout << s2 << endl;

    auto m1 = message_factory();
    message m2;

    m2 = message { "top secret message" };

    cout << m1 << endl;
    cout << m2 << endl;

    // e 13.50
    cout << "-----------------------------------" << endl;
    vector<String> v;

    for (size_t i { 0 } ; i < 10 ; ++i)
      {
        v.emplace_back(to_string(i));
      }
    // e 13.51
    // unique_ptr's move constructor are used.

    // e 13.51
    cout << "-----------------------------------" << endl;

    String ss { "123456789" };
    String ss2 { "987654321" };

    cout << "ss:  " << ss << endl;
    cout << "ss2: " << ss2 << endl;

    ss = std::move(ss2);

    cout << "ss:  " << ss << endl;
    cout << "ss2: " << ss2 << endl; // ss2 are gone.



    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
