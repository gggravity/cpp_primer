#include <bits/stdc++.h>

using namespace std;

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

class D : public X, public C
{
public:

  D() { cout << "calling D ..." << endl; }
};

class Base1
{
public:

  Base1() { cout << "calling Base1 ..." << endl; }

  virtual void print() { cout << "calling Base1 ..." << endl; }

  virtual ~Base1() { cout << "calling Base1 ..." << endl; }
};

class Base2
{
public:

  Base2() { cout << "calling Base2 ..." << endl; }

  virtual void print() { cout << "calling Base2 ..." << endl; }

  virtual ~Base2() { cout << "calling Base2 ..." << endl; }
};

class D1 : public Base1
{
public:

  D1() { cout << "calling D1 ..." << endl; }

  void print() override { cout << "calling D1 ..." << endl; }

  ~D1() override { cout << "calling D1 ..." << endl; }
};

class D2 : public Base2
{
public:

  D2() { cout << "calling D2 ..." << endl; }

  void print() override { cout << "calling D2 ..." << endl; }

  ~D2() override { cout << "calling D2 ..." << endl; }
};

class MI_ : public D1, public D2
{
public:

  MI_() { cout << "calling MI_ ..." << endl; }

  //      void print () override
  //        {
  //          D1::print();
  //        }

  ~MI_() override { cout << "calling MI_ ..." << endl; }
};

int main()
{
  D *pd = new D;

  X *px = pd;
  A *pa = pd;
  B *pb = pd;
  C *pc = pd;

  // all permitted
  cout << "*px: " << *px << endl;
  cout << "*pa: " << *pa << endl;
  cout << "*pb: " << *pb << endl;
  cout << "*pc: " << *pc << endl;

  cout << "constructing Base1 pointer ..." << endl;
  Base1 *pb1 = new MI_;
  cout << "constructing Base2 pointer ..." << endl;
  Base2 *pb2 = new MI_;
  cout << "constructing D1 pointer ..." << endl;
  D1 *pd1 = new MI_;
  cout << "constructing D2 pointer ..." << endl;
  D2 *pd2 = new MI_;

  cout << "-----------------------" << endl;
  pb1->print();
  pd1->print();
  pb2->print();

  cout << "--- destructors -------" << endl;
  delete pb2;
  cout << "-----------------------" << endl;
  delete pd1;
  cout << "-----------------------" << endl;
  delete pd2;
  cout << "-----------------------" << endl;

  return 0;
}
