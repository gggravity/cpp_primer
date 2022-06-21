#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U> auto compare (const T &, const U &)
{
  cout << typeid (T).name() << endl;
  cout << typeid (U).name() << endl;
}

template <typename T> T calc (T t, int i)
{
  cout << t << endl;
  cout << i << endl;
  return t;
}

template <typename T> T fcn (T t1, T t2)
{
  cout << t1 << endl;
  cout << t2 << endl;
  return t1;
}

template <typename T> auto f1 (T t1, T t2)
{
  cout << *t1 << " " << *t2 << endl;
  return t1;
}

template <typename T1, typename T2> auto f2 (T1 t1, T2 t2) { cout << *t1 << " " << *t2 << endl; }

int main()
try
  {
    /*    compare("hi", "world");
        compare("bye", "dad");

        double d { 1 };
        float f { 2 };
        char c { 'C' };
        calc(c, 'c'); // fine, but 'c' is converted to int (99)
        calc(d, f); // work, but narrow conversion
        fcn(c, 'c'); // fine, both char
    //    fcn(d, f); // wrong, only one type and two arguments*/

    int i {0};
    int j {42};
    auto *p1 {&i};
    auto p2 {&j};
    const auto cp1 {&i};
    const auto cp2 {&j};

    f1 (p1, p2);
    f2 (p1, p2);
    f1 (cp1, cp2);
    f2 (cp1, cp2);
    f1 (p1, cp1);
    f2 (p1, cp1);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
