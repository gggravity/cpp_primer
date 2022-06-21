#pragma once
//
// Created by martin on 28-05-22.
//
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct employee
{
  string name;
  string adresse;
  string country;
  string phone;
  unsigned int id;

  bool operator== (const employee &rhs) const;

  bool operator!= (const employee &rhs) const;
};

istream &operator>> (istream &is, employee &employee);

ostream &operator<< (ostream &os, const employee &employee);
