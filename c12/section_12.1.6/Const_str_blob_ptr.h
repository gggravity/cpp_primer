//
// Created by martin on 24/05/2022.
//

# pragma once

#include <bits/stdc++.h>

class Str_blob;

using namespace std;

class Const_str_blob_ptr
      {
      public:
            Const_str_blob_ptr ();

            explicit Const_str_blob_ptr (const Str_blob &a, size_t sz = 0);

            [[nodiscard]] string &dereference () const;

            Const_str_blob_ptr &increment ();

      private:
            shared_ptr<vector<string>> check (size_t i, const string &msg) const;

            weak_ptr<vector<string>> w_ptr;
            size_t current;
      };


