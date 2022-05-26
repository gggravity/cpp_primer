//
// Created by martin on 26/05/2022.
//

#include "has_ptr.h"

has_ptr::has_ptr (const string &s) :
    ps(new string(s)),
    i(0),
    use(new size_t(1))
  {
    cout << "constructor called" << endl;
  }

has_ptr::has_ptr (const has_ptr &rhs) :
    ps(new string { *rhs.ps }),
    i(rhs.i),
    use(rhs.use)
  {
    ++*use;
    cout << "copy constructor called." << endl;
  }

has_ptr &has_ptr::operator= (const has_ptr &rhs)
  {
    cout << "copy assignment constructor called." << endl;

    if (this == &rhs)
      {
        return *this;
      }

    ++*rhs.use;

    if (--*use == 0)
      {
        delete ps;
        delete use;
      }

    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;

    return *this;
  }

has_ptr::~has_ptr ()
  {
    cout << "destructor called" << endl;

    if (--*use == 0)
      {
        delete ps;
        delete use;
      }
  }

ostream &operator<< (ostream &os, const has_ptr &ptr)
  {
    os << "ps: " << *ptr.ps << " i: " << ptr.i << " &ps: " << ptr.ps;
    return os;
  }

