#pragma once
//
// Created by martin on 05/06/2022.
//
#include <bits/stdc++.h>

using namespace std;

class DebugDelete
{
public:

  explicit DebugDelete (ostream &os = cerr) : os (os) {}

  template <typename T> void operator() (T *p) const
  {
    os << "deleting pointer at: " << p << endl;
    delete p;
  }

private:

  ostream &os;
};