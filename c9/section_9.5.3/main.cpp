#include <bits/stdc++.h>

using namespace std;

void find_if_alpha (const string &s)
  {
    string alpha { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

    for (string::size_type pos { 0 } ; ( pos = s.find_first_of(alpha, pos) ) != string::npos ; ++pos)
      {
        cout << "found alpha: " << s.at(pos) << " at position " << pos << endl;
      }
  }

void find_if_numeric (const string &s)
  {
    string numeric { "0123456789" };

    for (string::size_type pos { 0 } ; ( pos = s.find_first_of(numeric, pos) ) != string::npos ; ++pos)
      {
        cout << "found numeric: " << s.at(pos) << " at position " << pos << endl;
      }
  }

void find_if_alpha_v2 (const string &s)
  {
    string numeric { "0123456789" };

    for (string::size_type pos { 0 } ; ( pos = s.find_first_not_of(numeric, pos) ) != string::npos ; ++pos)
      {
        cout << "found alpha: " << s.at(pos) << " at position " << pos << endl;
      }
  }

void find_if_numeric_v2 (const string &s)
  {
    string alpha { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

    for (string::size_type pos { 0 } ; ( pos = s.find_first_not_of(alpha, pos) ) != string::npos ; ++pos)
      {
        cout << "found numeric: " << s.at(pos) << " at position " << pos << endl;
      }
  }

void find_largest_ascender_or_descender (const string &s)
  {
    unsigned long largest { 0 };
    string found_word;
    string ascenders { "bdfhklt" };
    string descenders { "gjpq'" };
    string type;

    istringstream iss { s };

    for (string word ; iss >> word ;)
      {
        auto pos_ascender = word.find_last_of(ascenders);
        if (( pos_ascender + 1 ) != 0 && pos_ascender > largest)
          {
            largest = pos_ascender;
            found_word = word;
            type = "ascender";
          }

        auto pos_descenders = word.find_last_of(descenders);
        if (( pos_descenders + 1 ) != 0 && pos_descenders > largest)
          {
            largest = pos_descenders;
            found_word = word;
            type = "descender";
          }
      }
    cout << "Found largest " << type << " at position " << largest << " in word \"" << found_word << "\"" << endl;
  }

int main (int argc, char *argv[])
try
  {
    // e 9.47
    string s { "ab2c3d7R4E6" };

    find_if_alpha(s);
    cout << "------------" << endl;
    find_if_numeric(s);
    cout << "------------" << endl;
    find_if_alpha_v2(s);
    cout << "------------" << endl;
    find_if_numeric_v2(s);

    // e 9.48

    cout << "------------" << endl;

    string name { "AnnaBella" };
    string numbers { "0123456789" };

    cout << numbers.find(name) << endl; // -1 of an unsigned eq. underflow -> largest number.
    cout << numbers.find(name) + 1 << endl;

    // e 9.49

    cout << "------------" << endl;

    string ad {
        "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum" };

    find_largest_ascender_or_descender(ad);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


