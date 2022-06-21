#include <bits/stdc++.h>

using namespace std;

unique_ptr<const char[]> concat (const char *p1, const char *p2)
{
  unique_ptr<char[]> text (new char[strlen (p1) + strlen (p2) + 1]);
  strcpy (text.get(), p1);
  strcat (text.get(), p2);

  return text;
}

string concat_string (const string &p1, const string &p2) { return p1 + p2; }

int main()
try
  {
    // e 12.23

    auto text = concat ("part_1", "part_2");

    cout << text << endl;

    auto text_string = concat_string ("part_1", "part_2");

    cout << text_string << endl;

    // e 12.24
    istringstream iss {
        "fsjkfhksdjfhksldfhlskdjhfskjldfhkljghdfklghdfkjghdfkjlghdfkjlghdflkghdfjkghdkfsdjfhksldfhlskdjhfskjldfhkljghdfklghdfkjghdfkjlghdfkjlghdflkghdfjkghdkfljghdfkljghdfkljgh"};

    constexpr int max {50};
    unique_ptr<char[]> line (new char[max]);
    char c;
    for (int i {0}; i < 50 && iss >> c; ++i)
      {
        line[i] = c;
      }
    cout << line << endl;

    // e 12.25

    int *pa = new int[10];
    delete[] pa;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
