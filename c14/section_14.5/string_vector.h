#pragma once
//
// Created by martin on 27-05-22.
//
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class string_vector
   {
   public:
      string_vector ();

      string_vector (initializer_list<string> initializer_list);

      string_vector (const string_vector &other);

      string_vector &operator= (const string_vector &other);

      string_vector &operator= (string_vector &&other) noexcept;

      string_vector (string_vector &&other) noexcept;

      string &operator[] (size_t n);

      const string &operator[] (size_t n) const;

      ~string_vector ();

      void push_back (const string &string);

      inline size_t size () const;

      [[nodiscard]] size_t capacity () const;

      void reserve (size_t n);

      [[nodiscard]] string *begin () const;

      [[nodiscard]] string *end () const;

      friend ostream &operator<< (ostream &os, const string_vector &vector);

      friend bool operator== (const string_vector &lhs, const string_vector &rhs);

      friend bool operator!= (const string_vector &lhs, const string_vector &rhs);

   private:
      static allocator<string> alloc;

      string *elements;    // pointer to the first element in the array
      string *first_free;  // pointer tro the first free element in the array
      string *cap;         // pointer to one past the end of the array

      void check_and_allocate ();

      pair<string *, string *> allocate_and_copy (const string *begin, const string *end);

      void free ();

      void reallocate (size_t new_capacity = 0);

   };