#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U, typename V> void f1 (T t, U u, V v)
{
  cout << typeid (T).name() << " = " << t << endl;
  cout << typeid (U).name() << " = " << u << endl;
  cout << typeid (V).name() << " = " << v << endl;
}

template <typename T> T f2 (T &t) { return t; }

template <typename T> inline T foo (T t, unsigned int *u)
{
  cout << "&u = " << u << endl;

  for (size_t i {0}; i < t; ++i)
    {
      cout << u[i] << " ";
    }
  cout << endl;

  return t;
}

template <typename T> void f4 (T t1, T t2) { cout << t1 + t2 << endl; }

typedef char Ctype;

template <typename Ctype> Ctype f5 (Ctype a)
{
  cout << typeid (Ctype).name() << " = " << a << endl;
  return a;
}

template <typename Container> void print (const Container &container)
{
  for (typename Container::size_type i {0}; i != container.size(); ++i)
    {
      cout << container[i] << " ";
    }
  cout << endl;
}

template <typename Container> void print_iterator (const Container &container)
{
  for (auto iterator {container.begin()}; iterator != container.end(); ++iterator)
    {
      cout << *iterator << " ";
    }
  cout << endl;
}

int main()
try
  {
    f1<int, string, double> (1, "one", 1.00);

    string s {"some string"};
    cout << f2<string> (s);

    cout << "---------------" << endl;

    unsigned int ia[] {1, 2, 3, 4, 5, 6};
    auto ret_val = foo<int> (6, ia);
    cout << "ret_val: " << ret_val << endl;

    cout << "---------------" << endl;

    f4<int> (10, 20);
    f4<string> ("10", "20");

    cout << "---------------" << endl;

    auto ret = f5 ('a');
    cout << ret << endl;

    cout << "---------------" << endl;

    vector<string> vs {"A", "B", "C"};
    vector<int> vi {1, 2, 3};
    print (vs);
    print (vi);

    cout << "---------------" << endl;

    print_iterator (vs);
    print_iterator (vi);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
