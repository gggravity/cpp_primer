#pragma once

#include <bits/stdc++.h>

class Str_blob_ptr;

class Const_str_blob_ptr;

using namespace std;

typedef vector<string>::size_type size_type;

class Str_blob
{
  friend class Str_blob_ptr;

  friend class Const_str_blob_ptr;

public:

  Str_blob();

  Str_blob (initializer_list<string> il);

  Str_blob (const Str_blob &rhs);

  Str_blob &operator= (const Str_blob &rhs);

  string &operator[] (size_t n);

  const string &operator[] (size_t n) const;

  virtual ~Str_blob();

  [[nodiscard]] size_type size() const;

  [[nodiscard]] bool empty() const;

  void push_back (const string &t);

  void push_back (string &&t);

  void pop_pack();

  string &front();

  string &back();

  Str_blob_ptr begin();

  Str_blob_ptr end();

  friend ostream &operator<< (ostream &os, const Str_blob &blob);

  friend bool operator== (const Str_blob &lhs, const Str_blob &rhs);

  friend bool operator!= (const Str_blob &lhs, const Str_blob &rhs);

private:

  shared_ptr<vector<string>> data;

  void check (size_type i, const string &msg) const;
};
