#include <bits/stdc++.h>

using namespace std;

class Class
{
public:

  Class() { cout << "running Class..." << endl; }

  ~Class()
  {
    //          cout << "running Class..." << endl;
  }
};

class Base : public Class
{
public:

  Base() { cout << "running Base..." << endl; }

  ~Base()
  {
    //          cout << "running Base..." << endl;
  }
};

class D1 : virtual public Base
{
public:

  D1() { cout << "running D1..." << endl; }

  ~D1()
  {
    //          cout << "running D1..." << endl;
  }
};

class D2 : virtual public Base
{
public:

  D2() { cout << "running D2..." << endl; }

  ~D2()
  {
    //          cout << "running D2..." << endl;
  }
};

class MI : public D1, public D2
{
public:

  MI() { cout << "running MI..." << endl; }

  ~MI()
  {
    //          cout << "running MI..." << endl;
  }
};

class Final : public MI, public Class
{
public:

  Final() { cout << "running Final..." << endl; }

  ~Final()
  {
    //          cout << "running Final..." << endl;
  }
};

int main()
{
  Class c;
  cout << "---------------------" << endl;
  Base b;
  cout << "---------------------" << endl;
  D1 d_1;
  cout << "---------------------" << endl;
  D2 d_2;
  cout << "---------------------" << endl;
  MI mi;
  cout << "---------------------" << endl;
  Final final;

  //    Base *pb;
  //    Class *cp;
  //    MI *pmi;
  //    D2 *pd2;
  //
  //    pb = new Class;
  //    pc = new Final;
  //    pmi = pb;
  //    pd2 = pmi;

  return 0;
}
