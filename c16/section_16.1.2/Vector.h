#pragma once
//
// Created by martin on 05-06-22.
//
#include <bits/stdc++.h>

using namespace std;

template < typename T >
class Vector
   {
   public:
      Vector () :
          elements(nullptr),
          first_free(nullptr),
          cap(nullptr)
        {

        }

      Vector (initializer_list<T> initializer_list) :
          elements(nullptr),
          first_free(nullptr),
          cap(nullptr)
        {
          for (auto &s : initializer_list)
            {
              push_back(s);
            }
        }

      Vector (const Vector &other)
        {
          auto new_data = allocate_and_copy(other.begin(), other.end());
          elements = new_data.first;
          first_free = cap = new_data.second;
        }

      Vector &operator= (const Vector &other)
        {
          if (this == &other)
            {
              return *this;
            }
          auto data = allocate_and_copy(other.begin(), other.end());
          free();
          elements = data.first;
          first_free = cap = data.second;
          return *this;
        }

      ~Vector ()
        {
          free();
        }

      void push_back (const T &t)
        {
          check_and_allocate();
          alloc.construct(first_free++, t);
        }

      [[nodiscard]] inline size_t size () const
        {
          return first_free - elements;
        }

      [[nodiscard]] size_t capacity () const
        {
          return cap - elements;
        }

      void reserve (size_t n)
        {
          reallocate(n);
        }

      [[nodiscard]] T *begin () const
        {
          return elements;
        }

      [[nodiscard]] T *end () const
        {
          return first_free;
        }

   private:
      static allocator<T> alloc;

      T *elements;    // pointer to the first element in the array
      T *first_free;  // pointer tro the first free element in the array
      T *cap;         // pointer to one past the end of the array

      void check_and_allocate ()
        {
          if (size() == capacity())
            {
              reallocate();
            }
        }

      pair<T *, T *> allocate_and_copy (const T *begin, const T *end)
        {
          auto data = alloc.allocate(end - begin);
          return { data, uninitialized_copy(begin, end, data) };
        }

      void free ()
        {
          if (elements)
            {
//              for (auto ptr = first_free ; ptr != elements ; /* empty */)
//                {
//                  alloc.destroy(--ptr);
//                }
              for_each(elements, first_free, [] (T &t)
                {
                    alloc.destroy(&t);
                });
              alloc.deallocate(elements, cap - elements);
            }
        }

      void reallocate (size_t new_capacity = 0)
        {
          if (!new_capacity)
            {
              new_capacity = size() ? 2 * size() : 1;
            }

          auto new_data = alloc.allocate(new_capacity);

          auto destination = new_data;
          auto element = elements;

          for (size_t i { 0 } ; i != size() ; ++i)
            {
              alloc.construct(destination++, std::move(*element++));
            }

          free();
          elements = new_data;
          first_free = destination;
          cap = elements + new_capacity;
        }

   };

template < typename T >
allocator<T> Vector<T>::alloc;