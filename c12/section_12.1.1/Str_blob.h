#pragma once

#include <bits/stdc++.h>

using namespace std;

class Str_blob
      {
      public:
            typedef vector<string>::size_type size_type;

            Str_blob ();

            Str_blob (initializer_list<string> il);

            [[nodiscard]] size_type size () const
              {
                return data->size();
              }

            [[nodiscard]] bool empty () const
              {
                return data->empty();
              }

            void push_back (const string &t)
              {
                data->push_back(t);
              }

            void pop_pack ();

            string &front ();

            string &back ();

      private:
            shared_ptr<vector<string>> data;

            void check (size_type i, const string &msg) const;
      };
