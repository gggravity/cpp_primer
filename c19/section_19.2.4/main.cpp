#include <bits/stdc++.h>

using namespace std;

class Sales_data
{
};

struct Base
{
};

struct Derived : Base
{
};

template <typename Type> string get_type (Type t)
{
  string type = typeid (t).name();

  while (isdigit (type[0]))
    {
      type = type.substr (1);
    }

  if (type == "i")
    {
      return "int";
    }
  if (type[0] == 'P' && isdigit (type[1]) || (type[1] == 'i' && type.size() == 2))
    {
      return "Pointer to " + type.substr (1);
    }

  if (type.find ("basic_string") != string::npos)
    {
      return "basic_string";
    }

  return type;
}

class A
{
public:

  A() = default;

  virtual ~A() = default;
};

class B : public A
{
public:

  B() = default;

  virtual ~B() = default;
};

class C : public B
{
public:

  C() = default;

  virtual ~C() = default;
};

int main()
{
  int arr[10];
  Derived d;
  Base *p = &d;

  cout << typeid (42).name() << ", " << typeid (arr).name() << ", " << typeid (Sales_data).name() << ", "
       << typeid (std::string).name() << ", " << typeid (p).name() << ", " << typeid (*p).name() << endl;

  cout << get_type (42) << ", " << get_type (arr) << ", " << get_type (Sales_data {}) << ", "
       << get_type (std::string {}) << ", " << get_type (p) << ", " << get_type (*p) << endl;

  A *pa = new C;
  cout << typeid (pa).name() << endl;

  C cobj;
  A &ra = cobj;
  cout << typeid (&ra).name() << endl;

  B *px = new B;
  A &rb = *px;
  cout << typeid (rb).name() << endl;

  return 0;
}
