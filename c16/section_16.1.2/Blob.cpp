//
// Created by martin on 23/05/2022.
//

//#include "Blob.h"
//#include "BlobPtr.h"


//template < typename T >
//Blob<T>::Blob (const Blob &rhs) : // copy constructor
//    data(make_shared<vector<T>>(*rhs.data))
//  {
//    cout << "copy constructor called." << endl;
//  }
//
//template < typename T >
//Blob<T> &Blob<T>::operator= (const Blob &rhs) // copy assignment operator
//  {
//    cout << "copy assignment operator called." << endl;
//    if (this == &rhs)
//      {
//        return *this;
//      }
//    data = make_shared<vector<string >>(*rhs.data);
//    return *this;
//  }
//
//template < typename T >
//Blob<T>::~Blob ()
//  {
////    cout << "destroying str_blob" << endl;
//  }
//
//template < typename T >
//size_t Blob<T>::size () const
//  {
//    return data->size();
//  }
//
//template < typename T >
//bool Blob<T>::empty () const
//  {
//    return data->empty();
//  }
//
//template < typename T >
//void Blob<T>::push_back (const T &t)
//  {
//    data->push_back(t);
//  }
//
//template < typename T >
//void Blob<T>::push_back (T &&t)
//  {
//    data->push_back(std::move(t));
//  }
//
//template < typename T >
//void Blob<T>::pop_pack ()
//  {
//    check(0, "pop_back on empty Str_blob");
//    data->pop_back();
//  }
//
//template < typename T >
//T &Blob<T>::front ()
//  {
//    check(0, "front on empty Str_blob");
//    return data->front();
//  }
//
//template < typename T >
//T &Blob<T>::back ()
//  {
//    check(0, "back on empty Str_blob");
//    return data->back();
//  }
//
//template < typename T >
//BlobPtr<T> Blob<T>::begin ()
//  {
//    return { *this };
//  }
//
//template < typename T >
//BlobPtr<T> Blob<T>::end ()
//  {
//    return { *this, data->size() };
//  }
//
//template < typename T >
//void Blob<T>::check (size_t i, const string &msg) const
//  {
//    if (i >= data->size())
//      {
//        throw out_of_range(msg);
//      }
//  }
//
//template < typename U >
//ostream &operator<< (ostream &os, const Blob<U> &blob)
//  {
//    for (auto &s : *blob.data)
//      {
//        cout << s;
//        if (s != ( *blob.data ).back())
//          {
//            cout << " ";
//          }
//      }
//
//    return os;
//  }
//
//template < typename U >
//bool operator== (const Blob<U> &lhs, const Blob<U> &rhs)
//  {
//    return *lhs.data == *rhs.data;
//  }
//
//template < typename U >
//bool operator!= (const Blob<U> &lhs, const Blob<U> &rhs)
//  {
//    return !( *rhs.data == *lhs.data );
//  }
//
//template < typename T >
//T &Blob<T>::operator[] (size_t n)
//  {
//    return ( *data )[n];
//  }
//
//template < typename T >
//const T &Blob<T>::operator[] (size_t n) const
//  {
//    return ( *data )[n];
//  }
//
