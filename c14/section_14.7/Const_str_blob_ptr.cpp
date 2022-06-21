//
// Created by martin on 24/05/2022.
//

#include "Const_str_blob_ptr.h"
#include "Str_blob.h"

Const_str_blob_ptr::Const_str_blob_ptr() : current (0) {}

Const_str_blob_ptr::Const_str_blob_ptr (const Str_blob &a, size_t sz) : w_ptr (a.data), current (sz) {}

string &Const_str_blob_ptr::dereference() const
{
  //    auto p = check(current, "dereference past end");
  //    return ( *p )[current];

  return (*check (current, "dereference past end"))[current];
}

Const_str_blob_ptr &Const_str_blob_ptr::increment()
{
  check (current, "increment past end of Str_blob_ptr");
  ++current;
  return *this;
}

shared_ptr<vector<string>> Const_str_blob_ptr::check (size_t i, const string &msg) const
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

const string &Const_str_blob_ptr::operator*() const
{
  auto p = check (current, "dereference past end");
  return (*p)[current];
}

const string *Const_str_blob_ptr::operator->() const { return &this->operator*(); }
