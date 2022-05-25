//
// Created by martin on 24/05/2022.
//

# pragma once

#include <bits/stdc++.h>

class Str_blob;

using namespace std;

class Str_blob_ptr
      {
      public:
            Str_blob_ptr ();

            explicit Str_blob_ptr (Str_blob &a, size_t sz = 0);

            [[nodiscard]] string &dereference () const;

            Str_blob_ptr &increment ();

      private:
            shared_ptr<vector<string>> check (size_t i, const string &msg) const;

            weak_ptr<vector<string>> w_ptr;
            size_t current;
      };


