//
// Created by martin on 24/05/2022.
//

# pragma once

#include <bits/stdc++.h>
#include "Blob.h"

template < typename T >
class Blob;

using namespace std;

template < typename T >
class BlobPtr
   {
   public:
      BlobPtr () :
          current(0)
        {

        }

      BlobPtr (Blob<T> &a, size_t sz = 0)
      try :
          w_ptr(a.data),
          current(sz)
        {

        }
      catch (bad_alloc &e)
        {
          cout << "ERROR" << endl;
        }

      BlobPtr &operator= (const BlobPtr &rhs)
        {
          if (this == &rhs)
            { //is there any need of self-assignment .
              return *this;
            }

          w_ptr = rhs.w_ptr;
          current = rhs.current;

          cout << "copy assignment constructor called." << endl;

          return *this;
        }

      T &operator[] (size_t n)
        {
          if (auto spt = w_ptr.lock())
            {
              return ( *spt )[n];
            }
          else
            {
              throw runtime_error("weak pointer is expired");
              exit(EXIT_FAILURE);
            }
        }

      const string &operator[] (size_t n) const
        {
          if (auto spt = w_ptr.lock())
            {
              return ( *spt )[n];
            }
          else
            {
              throw runtime_error("weak pointer is expired");
              exit(EXIT_FAILURE);
            }
        }

      BlobPtr &operator+ ()
        {
          return ++*this;
        }

      BlobPtr &operator- ()
        {
          return --*this;
        }

      BlobPtr &operator++ ()
        {
          auto ret = check(current, "increment past end of Str_blob_ptr");
          ++current;
          return *this;
        }

      BlobPtr &operator-- ()
        {
          --current;
          auto ret = check(current, "increment past begin of Str_blob_ptr");
          return *this;
        }

      BlobPtr operator++ (int)
        {
          auto ret = *this;
          ++*this;
          return ret;
        }

      BlobPtr operator-- (int)
        {
          auto ret = *this;
          --*this;
          return ret;
        }

      T &operator* () const
        {
          auto p = check(current, "dereference past end");
          return ( *p )[current];
        }

      T *operator-> () const
        {
          return &this->operator*();
        }

      virtual ~BlobPtr ()
        {
//    cout << "destroying str_blob_ptr" << endl;
        }

      [[nodiscard]] size_t size () const
        {
          if (auto spt = w_ptr.lock())
            {
              return ( *spt ).size();
            }
          else
            {
              throw runtime_error("weak pointer is expired");
              exit(EXIT_FAILURE);
            }
        }

      [[nodiscard]] T &dereference () const
        {
//    auto p = check(current, "dereference past end");
//    return ( *p )[current];

          return ( *check(current, "dereference past end") )[current];
        }

      BlobPtr &increment ()
        {
          auto ret = check(current, "increment past end of Str_blob_ptr");
          ++current;
          return *this;
        }

      template < typename U >
      friend bool operator== (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

      template < typename U >
      friend bool operator!= (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

      template < typename U >
      friend ostream &operator<< (ostream &os, const BlobPtr<T> &ptr);

   private:
      [[nodiscard]] shared_ptr<vector<T>> check (size_t i, const string &msg) const
        {
          auto ret = w_ptr.lock();
          if (!ret)
            {
              throw runtime_error("unbound Str_blob_ptr");
            }
          if (i >= ret->size())
            {
              throw out_of_range(msg);
            }
          return ret;
        }

      weak_ptr<vector<T>> w_ptr;
      size_t current;
   };

template < typename U >
bool operator== (const BlobPtr<U> &lhs, const BlobPtr<U> &rhs)
  {
    auto lhs_ptr = lhs.w_ptr.lock();
    auto rhs_ptr = rhs.w_ptr.lock();

    if (!( lhs_ptr && rhs_ptr ))
      {
        throw runtime_error("weak pointer is expired");
        return false;
      }

    return *lhs_ptr == *rhs_ptr &&
           lhs.current == rhs.current;
  }

template < typename U >
bool operator!= (const BlobPtr<U> &lhs, const BlobPtr<U> &rhs)
  {
    return !( rhs == lhs );
  }

template < typename U >
ostream &operator<< (ostream &os, const BlobPtr<U> &ptr)
  {
//    if (auto spt = ptr.w_ptr.lock())
//      {
//        for (auto &s : *spt)
//          {
//            cout << s;
//            if (s != spt->back())
//              {
//                cout << " ";
//              }
//          }
//      }
//    else
//      {
//        std::cout << "weak pointer is expired" << endl;
//      }
    if (auto spt = ptr.w_ptr.lock())
      {
        cout << ( *spt )[ptr.current];
      }
    else
      {
        std::cout << "weak pointer is expired" << endl;
      }
    return os;
  }