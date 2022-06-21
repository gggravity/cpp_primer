#pragma once

//
// Created by martin on 26/05/2022.
//

#include <bits/stdc++.h>

using namespace std;

class has_ptr
{
public:

  explicit has_ptr (const string &s = string());

  has_ptr (const has_ptr &rhs);

  has_ptr &operator= (const has_ptr &rhs);

  virtual ~has_ptr();

  friend ostream &operator<< (ostream &os, const has_ptr &ptr);

private:

  string *ps;
  int i;
  size_t *use;
};
