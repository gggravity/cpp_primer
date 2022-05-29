//
// Created by martin on 24/05/2022.
//

# pragma once

#include <bits/stdc++.h>
#include <ostream>

class Str_blob;

using namespace std;

class Str_blob_ptr
   {
   public:
      Str_blob_ptr ();

      explicit Str_blob_ptr (Str_blob &a, size_t sz = 0);

      Str_blob_ptr &operator= (const Str_blob_ptr &rhs);

      string &operator[] (size_t n);

      const string &operator[] (size_t n) const;

      virtual ~Str_blob_ptr ();

      [[nodiscard]] string &dereference () const;

      Str_blob_ptr &increment ();

      friend bool operator== (const Str_blob_ptr &lhs, const Str_blob_ptr &rhs);

      friend bool operator!= (const Str_blob_ptr &lhs, const Str_blob_ptr &rhs);

      friend ostream &operator<< (ostream &os, const Str_blob_ptr &ptr);

   private:
      [[nodiscard]] shared_ptr<vector<string>> check (size_t i, const string &msg) const;

      weak_ptr<vector<string>> w_ptr;
      size_t current;
   };


