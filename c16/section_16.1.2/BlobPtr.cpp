//
// Created by martin on 24/05/2022.
//

#include "BlobPtr.h"
#include "Blob.h"

template < typename T >
BlobPtr<T>::BlobPtr ()
    : current(0)
  {

  }

template < typename T >
BlobPtr<T>::BlobPtr (Blob<T> &a, size_t sz)
    : w_ptr(a.data),
    current(sz)
  {

  }

template < typename T >
BlobPtr<T> &BlobPtr<T>::operator= (const BlobPtr &rhs)
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

template < typename T >
string &BlobPtr<T>::dereference () const
  {
//    auto p = check(current, "dereference past end");
//    return ( *p )[current];

    return ( *check(current, "dereference past end") )[current];
  }

template <typename T>
BlobPtr<T> &BlobPtr<T>::increment ()
  {
    auto ret = check(current, "increment past end of Str_blob_ptr");
    ++current;
    return *this;
  }

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check (size_t i, const string &msg) const
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

template <typename T>
BlobPtr<T>::~BlobPtr ()
  {
//    cout << "destroying str_blob_ptr" << endl;
  }

template <typename U>
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

template <typename U>
bool operator!= (const BlobPtr<U> &lhs, const BlobPtr<U> &rhs)
  {
    return !( rhs == lhs );
  }

template <typename U>
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

template <typename T>
string &BlobPtr<T>::operator[] (size_t n)
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

template <typename T>
const string &BlobPtr<T>::operator[] (size_t n) const
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

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++ ()
  {
    auto ret = check(current, "increment past end of Str_blob_ptr");
    ++current;
    return *this;
  }

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator-- ()
  {
    --current;
    auto ret = check(current, "increment past begin of Str_blob_ptr");
    return *this;
  }

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++ (int)
  {
    auto ret = *this;
    ++*this;
    return ret;
  }

template <typename T>
BlobPtr<T> BlobPtr<T>::operator-- (int)
  {
    auto ret = *this;
    --*this;
    return ret;
  }

template <typename T>
size_t BlobPtr<T>::size () const
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

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator+ ()
  {
    return ++*this;
  }

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator- ()
  {
    return --*this;
  }

template <typename T>
string &BlobPtr<T>::operator* () const
  {
    auto p = check(current, "dereference past end");
    return ( *p )[current];
  }

template <typename T>
string *BlobPtr<T>::operator-> () const
  {
    return &this->operator*();
  }
