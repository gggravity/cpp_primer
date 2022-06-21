#include <bits/stdc++.h>

using namespace std;

class CAD
{
};

class Vehicle
{
};

class List
{
};

class CADVehicle : public CAD, Vehicle
{
};

// class DblList : public List, public List
//    {
//    };

class DblList : public List
{
};

class IOstream : public istream, public ostream
{
};

class A
{
public:

  A() : a ("default A") { cout << "calling A ..." << endl; }

  explicit A (string a) : a (std::move (a)) { cout << "calling A ..." << endl; }

  friend ostream &operator<< (ostream &os, const A &output)
  {
    os << "a: " << output.a;
    return os;
  }

protected:

  string a;
};

class B : public A
{
public:

  B() : A ("from B"), b ("default B") { cout << "calling B ..." << endl; }
  explicit B (string b) : A ("from B"), b (std::move (b)) { cout << "calling B ..." << endl; }

  B (const string &a, string b) : A (a), b (std::move (b)) { cout << "calling B ..." << endl; }

  friend ostream &operator<< (ostream &os, const B &output)
  {
    os << "a: " << output.a << " b: " << output.b;
    return os;
  }

protected:

  string b;
};

class C : public B
{
public:

  C() : B ("from C"), c ("default C") { cout << "calling C ..." << endl; }

  explicit C (string c) : B ("from C"), c (std::move (c)) { cout << "calling C ..." << endl; }

  C (const string &a, const string &b, string c) : B (a, b), c (std::move (c)) { cout << "calling C ..." << endl; }

  friend ostream &operator<< (ostream &os, const C &output)
  {
    os << "a: " << output.a << " b: " << output.b << " c: " << output.c;
    return os;
  }

protected:

  string c;
};

class X
{
public:

  X() : x ("default X") { cout << "calling X ..." << endl; }

  explicit X (string x) : x (std::move (x)) { cout << "calling X ..." << endl; }

  friend ostream &operator<< (ostream &os, const X &output)
  {
    os << "x: " << output.x;
    return os;
  }

protected:

  string x;
};

class Y
{
public:

  Y() : y ("default Y") { cout << "calling Y ..." << endl; }
  explicit Y (string y) : y (std::move (y)) { cout << "calling Y ..." << endl; }

  friend ostream &operator<< (ostream &os, const Y &output)
  {
    os << "y: " << output.y;
    return os;
  }

protected:

  string y;
};

class Z : public X, public Y
{
public:

  Z() : X ("from Z"), Y ("from Z"), z ("default Z") { cout << "calling Z ..." << endl; }

  explicit Z (string z) : X ("from Z"), Y ("from Z"), z (std::move (z)) { cout << "calling Z ..." << endl; }

  Z (const string &x, const string &y, string z) : X (x), Y (y), z (std::move (z)) { cout << "calling Z ..." << endl; }

  friend ostream &operator<< (ostream &os, const Z &output)
  {
    os << "x: " << output.x << " y: " << output.y << " z: " << output.z;
    return os;
  }

protected:

  string z;
};

class MI : public C, public X
{
public:

  MI() : C ("from MI", "from MI", "from MI"), X ("from MI"), mi ("default MI") { cout << "calling MI ..." << endl; }
  explicit MI (string mi) : C ("from MI", "from MI", "from MI"), X ("from MI"), mi (std::move (mi))
  {
    cout << "calling MI ..." << endl;
  }

  MI (const string &a, const string &b, const string &c, const string &x, string mi)
      : C (a, b, c), X (x), mi (std::move (mi))
  {
    cout << "calling MI ..." << endl;
  }

  friend ostream &operator<< (ostream &os, const MI &output)
  {
    os << "a: " << output.a << " b: " << output.b << " c: " << output.c << " mi: " << output.mi;
    return os;
  }

protected:

  string mi;
};

int main()
{
  CADVehicle cad_vehicle;

  DblList dbl_list;

  IOstream io_stream;

  cout << "Constructing a ..." << endl;
  A a;
  cout << "Constructing b ..." << endl;
  B b;
  cout << "Constructing c ..." << endl;
  C c;
  cout << "Constructing x ..." << endl;
  X x;
  cout << "Constructing y ..." << endl;
  Y y;
  cout << "Constructing z ..." << endl;
  Z z;
  cout << "Constructing mi ..." << endl;
  MI mi;

  cout << "Running a ..." << endl;
  cout << a << endl;
  cout << "Running b ..." << endl;
  cout << b << endl;
  cout << "Running c ..." << endl;
  cout << c << endl;
  cout << "Running x ..." << endl;
  cout << x << endl;
  cout << "Running y ..." << endl;
  cout << y << endl;
  cout << "Running z ..." << endl;
  cout << z << endl;
  cout << "Running mi ..." << endl;
  cout << mi << endl;

  return 0;
}
