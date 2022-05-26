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

            Str_blob_ptr &operator= (const Str_blob_ptr &rhs)
              {
                if (this == &rhs)
                  { //is there any need of self-assignment .
                    return *this;
                  }

                w_ptr = rhs.w_ptr;
                current = rhs.current;

                cout << "copy assignment constructor called." << endl;

                return *this;
              };

            [[nodiscard]] string &dereference () const;

            Str_blob_ptr &increment ();

      private:
            [[nodiscard]] shared_ptr<vector<string>> check (size_t i, const string &msg) const;

            weak_ptr<vector<string>> w_ptr;
            size_t current;
      };


