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

Str_blob::Str_blob (const Str_blob &rhs) : // copy constructor
    data(make_shared<vector<string >>(*rhs.data))
  {
    cout << "copy constructor called." << endl;
  }

Str_blob &Str_blob::operator= (const Str_blob &rhs) // copy assignment operator
  {
    cout << "copy assignment operator called." << endl;
    if (this == &rhs)
      {
        return *this;
      }
    data = make_shared<vector<string >>(*rhs.data);
    return *this;
  }

Str_blob::~Str_blob ()
  {
//    cout << "destroying str_blob" << endl;
  }

size_type Str_blob::size () const
  {
    return data->size();
  }

bool Str_blob::empty () const
  {
    return data->empty();
  }

void Str_blob::push_back (const string &t)
  {
    data->push_back(t);
  }

void Str_blob::push_back (string &&t)
  {
    data->push_back(std::move(t));
  }

void Str_blob::pop_pack ()
  {
    check(0, "pop_back on empty Str_blob");
    data->pop_back();
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

Str_blob_ptr Str_blob::begin ()
  {
    return Str_blob_ptr(*this);
  }

Str_blob_ptr Str_blob::end ()
  {
    return Str_blob_ptr(*this, data->size());
  }

void Str_blob::check (size_type i, const string &msg) const
  {
    if (i >= data->size())
      {
        throw out_of_range(msg);
      }
  }

ostream &operator<< (ostream &os, const Str_blob &blob)
  {
    for (auto &s : *blob.data)
      {
        cout << s;
        if (s != ( *blob.data ).back())
          {
            cout << " ";
          }
      }

    return os;
  }

bool operator== (const Str_blob &lhs, const Str_blob &rhs)
  {
    return *lhs.data == *rhs.data;
  }

bool operator!= (const Str_blob &lhs, const Str_blob &rhs)
  {
    return !( *rhs.data == *lhs.data );
  }

string &Str_blob::operator[] (size_t n)
  {
    return (*data)[n];
  }

const string &Str_blob::operator[] (size_t n) const
  {
    return (*data)[n];
  }

