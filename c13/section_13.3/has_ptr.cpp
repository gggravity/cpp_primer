//
// Created by martin on 26/05/2022.
//

#include "has_ptr.h"

has_ptr::has_ptr (const string &s) :
    ps(new string(s)),
    i(0),
    use(new size_t(1))
  {
//    cout << "constructor called" << endl;
  }

has_ptr::has_ptr (const has_ptr &rhs) :
    ps(new string { *rhs.ps }),
    i(rhs.i),
    use(rhs.use)
  {
    ++*use;
//    cout << "copy constructor called." << endl;
  }

has_ptr &has_ptr::operator= (has_ptr rhs)
  {
//    cout << "copy assignment constructor called." << endl;

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

    swap(*this, rhs);

    return *this;
  }

bool has_ptr::operator< (const has_ptr &rhs)
  {
    return *this->ps < *rhs.ps;
  }

bool has_ptr::operator<= (const has_ptr &rhs)
  {
    return *this->ps <= *rhs.ps;
  }

has_ptr::~has_ptr ()
  {
//    cout << "destructor called" << endl;

    if (--*use == 0)
      {
        delete ps;
        delete use;
      }
  }

ostream &operator<< (ostream &os, const has_ptr &ptr)
  {
//    os << "ps: " << *ptr.ps << " i: " << ptr.i << " &ps: " << ptr.ps;
    os << *ptr.ps;
    return os;
  }

void has_ptr::set_ps (string *string)
  {
    has_ptr::ps = string;
  }

void has_ptr::swap (has_ptr &lhs, has_ptr &rhs)
  {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
  }
