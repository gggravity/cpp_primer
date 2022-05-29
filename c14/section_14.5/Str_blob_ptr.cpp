//
// Created by martin on 24/05/2022.
//

#include "Str_blob_ptr.h"
#include "Str_blob.h"

Str_blob_ptr::Str_blob_ptr ()
    : current(0)
  {

  }

Str_blob_ptr::Str_blob_ptr (Str_blob &a, size_t sz)
    : w_ptr(a.data),
    current(sz)
  {

  }

Str_blob_ptr &Str_blob_ptr::operator= (const Str_blob_ptr &rhs)
  {
    if (this == &rhs)
      { //is there any need of self-assignment .
        return *this;
      }

    w_ptr = rhs.w_ptr;
    current = rhs.current;

    cout << "copy assignment constructor called." << endl;

    return *this;
  };

string &Str_blob_ptr::dereference () const
  {
//    auto p = check(current, "dereference past end");
//    return ( *p )[current];

    return ( *check(current, "dereference past end") )[current];
  }

Str_blob_ptr &Str_blob_ptr::increment ()
  {
    auto ret = check(current, "increment past end of Str_blob_ptr");
    ++current;
    return *this;
  }

shared_ptr<vector<string>> Str_blob_ptr::check (size_t i, const string &msg) const
  {
    auto ret = w_ptr.lock();
    if (!ret)
      {
        throw runtime_error("unbound Str_blob_ptr");
      }
    if (i >= ret->size())
      {
        throw out_of_range(msg);
      }
    return ret;
  }

Str_blob_ptr::~Str_blob_ptr ()
  {
//    cout << "destroying str_blob_ptr" << endl;
  }

bool operator== (const Str_blob_ptr &lhs, const Str_blob_ptr &rhs)
  {
    auto lhs_ptr = lhs.w_ptr.lock();
    auto rhs_ptr = rhs.w_ptr.lock();

    if (!( lhs_ptr && rhs_ptr ))
      {
        throw runtime_error("weak pointer is expired");
        return false;
      }

    return *lhs_ptr == *rhs_ptr &&
           lhs.current == rhs.current;
  }

bool operator!= (const Str_blob_ptr &lhs, const Str_blob_ptr &rhs)
  {
    return !( rhs == lhs );
  }

ostream &operator<< (ostream &os, const Str_blob_ptr &ptr)
  {
    if (auto spt = ptr.w_ptr.lock())
      {
        for (auto &s : *spt)
          {
            cout << s;
            if (s != spt->back())
              {
                cout << " ";
              }
          }
      }
    else
      {
        std::cout << "weak pointer is expired" << endl;
      }

    return os;
  }

string &Str_blob_ptr::operator[] (size_t n)
  {
    if (auto spt = w_ptr.lock())
      {
        return ( *spt )[n];
      }
    else
      {
        throw runtime_error("weak pointer is expired");
        exit(EXIT_FAILURE);
      }
  }

const string &Str_blob_ptr::operator[] (size_t n) const
  {
    if (auto spt = w_ptr.lock())
      {
        return ( *spt )[n];
      }
    else
      {
        throw runtime_error("weak pointer is expired");
        exit(EXIT_FAILURE);
      }
  }
