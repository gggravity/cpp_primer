//
// Created by martin on 24/05/2022.
//

#include "Str_blob_ptr.h"
#include "Str_blob.h"

Str_blob_ptr::Str_blob_ptr() : current (0) {}

Str_blob_ptr::Str_blob_ptr (Str_blob &a, size_t sz) : w_ptr (a.data), current (sz) {}

Str_blob_ptr &Str_blob_ptr::operator= (const Str_blob_ptr &rhs)
{
  if (this == &rhs)
    {  // is there any need of self-assignment .
      return *this;
    }

  w_ptr = rhs.w_ptr;
  current = rhs.current;

  cout << "copy assignment constructor called." << endl;

  return *this;
};

string &Str_blob_ptr::dereference() const
{
  //    auto p = check(current, "dereference past end");
  //    return ( *p )[current];

  return (*check (current, "dereference past end"))[current];
}

Str_blob_ptr &Str_blob_ptr::increment()
{
  auto ret = check (current, "increment past end of Str_blob_ptr");
  ++current;
  return *this;
}

shared_ptr<vector<string>> Str_blob_ptr::check (size_t i, const string &msg) const
{
  auto ret = w_ptr.lock();
  if (! ret)
    {
      throw runtime_error ("unbound Str_blob_ptr");
    }
  if (i >= ret->size())
    {
      throw out_of_range (msg);
    }
  return ret;
}

Str_blob_ptr::~Str_blob_ptr() { cout << "destroying str_blob_ptr" << endl; }

bool operator== (const Str_blob_ptr &lhs, const Str_blob_ptr &rhs)
{
  // lhs.w_ptr == rhs.w_ptr
  // to compare waek pointers
  // https://stackoverflow.com/questions/12301916/equality-compare-stdweak-ptr
  return (! lhs.w_ptr.owner_before (rhs.w_ptr) && ! rhs.w_ptr.owner_before (lhs.w_ptr)) && lhs.current == rhs.current;
}

bool operator!= (const Str_blob_ptr &lhs, const Str_blob_ptr &rhs) { return ! (rhs == lhs); }
