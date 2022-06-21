#pragma once

#include <bits/stdc++.h>

class Str_blob_ptr;

class Const_str_blob_ptr;

using namespace std;

class Str_blob
{
  friend class Str_blob_ptr;

  friend class Const_str_blob_ptr;

public:

  typedef vector<string>::size_type size_type;

  Str_blob();

  Str_blob (initializer_list<string> il);

  Str_blob (const Str_blob &rhs)
      :  // copy constructor
        data (make_shared<vector<string>> (*rhs.data))
  {
    cout << "copy constructor called." << endl;
  };

  Str_blob &operator= (const Str_blob &rhs)  // copy assignment operator
  {
    cout << "copy assignment operator called." << endl;
    if (this == &rhs)
      {
        return *this;
      }
    data = make_shared<vector<string>> (*rhs.data);
    return *this;
  };

  virtual ~Str_blob();

  [[nodiscard]] size_type size() const { return data->size(); }

  [[nodiscard]] bool empty() const { return data->empty(); }

  void push_back (const string &t) { data->push_back (t); }

  void push_back (string &&t) { data->push_back (std::move (t)); }

  void pop_pack();

  string &front();

  string &back();

  Str_blob_ptr begin();

  Str_blob_ptr end();

  friend ostream &operator<< (ostream &os, const Str_blob &blob);

private:

  shared_ptr<vector<string>> data;

  void check (size_type i, const string &msg) const;
};
