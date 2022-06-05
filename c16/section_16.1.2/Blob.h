#pragma once

#include <bits/stdc++.h>
#include <ostream>
#include "BlobPtr.h"

template < typename T >
class BlobPtr;

using namespace std;

template < typename T >
class Blob
   {
      friend class BlobPtr<T>;

   public:

      Blob ()
          : data(make_shared<vector<T>>())
        {

        }

      Blob (initializer_list<T> il)
          : data(make_shared<vector<T>>(il))
        {

        }

      Blob (const Blob &rhs) : // copy constructor
          data(make_shared<vector<T>>(*rhs.data))
        {
          cout << "copy constructor called." << endl;
        }

      Blob &operator= (const Blob &rhs) // copy assignment operator
        {
          cout << "copy assignment operator called." << endl;
          if (this == &rhs)
            {
              return *this;
            }
          data = make_shared<vector<string >>(*rhs.data);
          return *this;
        }

      T &operator[] (size_t n)
        {
          return ( *data )[n];
        }

      const T &operator[] (size_t n) const
        {
          return ( *data )[n];
        }

      virtual ~Blob ()
        {
//          cout << "destroying str_blob" << endl;
        }

      [[nodiscard]] size_t size () const
        {
          return data->size();
        }

      [[nodiscard]] bool empty () const
        {
          return data->empty();
        }

      void push_back (const T &t)
        {
          data->push_back(t);
        }

      void push_back (T &&t)
        {
          data->push_back(std::move(t));
        }

      void pop_pack ()
        {
          check(0, "pop_back on empty Str_blob");
          data->pop_back();
        }

      T &front ()
        {
          check(0, "front on empty Str_blob");
          return data->front();
        }

      T &back ()
        {
          check(0, "back on empty Str_blob");
          return data->back();
        }

      BlobPtr<T> begin ()
        {
          return { *this };
        }

      BlobPtr<T> end ()
        {
          return { *this, data->size() };
        }

      template < typename U >
      friend bool operator== (const Blob<U> &lhs, const Blob<U> &rhs);

      template < typename U >
      friend bool operator!= (const Blob<U> &lhs, const Blob<U> &rhs);

      template < typename U >
      friend ostream &operator<< (ostream &os, const Blob<U> &blob);

   private:
      shared_ptr<vector<T>> data;

      void check (size_t i, const string &msg) const
        {
          if (i >= data->size())
            {
              throw out_of_range(msg);
            }
        }
   };

template < typename U >
ostream &operator<< (ostream &os, const Blob<U> &blob)
  {
//    os << "data: " << blob.data;
    for (auto &s : *blob.data)
      {
        os << s << " ";
      }
    return os;
  }

template < typename U >
bool operator== (const Blob<U> &lhs, const Blob<U> &rhs)
  {
    return *lhs.data == *rhs.data;
  }

template < typename U >
bool operator!= (const Blob<U> &lhs, const Blob<U> &rhs)
  {
    return !( *rhs.data == *lhs.data );
  }
