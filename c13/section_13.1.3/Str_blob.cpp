//
// Created by martin on 23/05/2022.
//

#include "Str_blob.h"
#include "Str_blob_ptr.h"

Str_blob::Str_blob ()
    : data(make_shared<vector<string>>())
  {

  }

Str_blob::Str_blob (initializer_list<string> il)
    : data(make_shared<vector<string>>(il))
  {

  }

void Str_blob::check (Str_blob::size_type i, const string &msg) const
  {
    if (i >= data->size())
      {
        throw out_of_range(msg);
      }
  }

string &Str_blob::front ()
  {
    check(0, "front on empty Str_blob");
    return data->front();
  }

string &Str_blob::back ()
  {
    check(0, "back on empty Str_blob");
    return data->back();
  }

void Str_blob::pop_pack ()
  {
    check(0, "pop_back on empty Str_blob");
    data->pop_back();
  }

Str_blob_ptr Str_blob::begin ()
  {
    return Str_blob_ptr(*this);
  }

Str_blob_ptr Str_blob::end ()
  {
    return Str_blob_ptr(*this, data->size());
  }

Str_blob::~Str_blob ()
  {
    cout << "destroying str_blob" << endl;
  }

