#pragma once
//
// Created by martin on 27-05-22.
//
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class String
   {
   public:
      String () = default;

      String (initializer_list<char> initializer_list);

      explicit String (const string& string);

      explicit String (const char* c_string);

      String (const String &other);

      String &operator= (const String &other);

      String &operator= (const char* other);

      String &operator= (String &&other) noexcept;

      String (String &&other) noexcept;

      ~String ();

      void push_back (const char &c);

      inline size_t size () const;

      size_t capacity () const;

      void reserve (size_t n);

      [[nodiscard]] char *begin () const;

      [[nodiscard]] char *end () const;

      friend ostream &operator<< (ostream &os, const String &string);

   private:
      static allocator<char> alloc;

      char *elements { nullptr };    // pointer to the first element in the array
      char *first_free { nullptr };  // pointer tro the first free element in the array
      char *cap { nullptr };         // pointer to one past the end of the array

      void check_and_allocate ();

      static pair<char *, char *> allocate_and_copy (const char *begin, const char *end);

      void free ();

      void reallocate (size_t new_capacity = 0);
   };