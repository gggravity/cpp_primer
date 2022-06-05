#pragma once
//
// Created by martin on 05/06/2022.
//

#include <ostream>

using namespace std;

struct DebugDelete
   {
      template < typename T >
      auto operator() (T *p) const
        {
          cout << "deleting pointer at: " << p << endl;
          delete p;
        }
   };

template < typename T, typename D = DebugDelete >
class UniquePointer
   {
   public:

      UniquePointer (const UniquePointer &) = delete;

      UniquePointer &operator= (const UniquePointer &) = delete;

      UniquePointer (T *ptr = nullptr, const D &d = D()) noexcept :
          current_ptr(ptr),
          deleter(d)
        {

        }

      UniquePointer (UniquePointer &&other) noexcept :
          current_ptr(other.current_ptr),
          deleter(std::move(other.deleter))
        {
          other.current_ptr = nullptr;
        }

      UniquePointer &operator= (UniquePointer &&other) noexcept
        {
          if (this != &other)
            {
              reset();
              current_ptr = other.current_ptr;
              deleter = std::move(other.deleter);
              other.current_ptr = nullptr;
            }

          return *this;
        }

      T &operator* () const
        {
          if (current_ptr == nullptr)
            {
              cerr << "No pointer at address" << endl;
              exit(EXIT_FAILURE);
            }

          return *current_ptr;
        }

      T *operator-> () const noexcept
        {
          return get();
        }

      T &operator[] (size_t i) const noexcept
        {
          return current_ptr[i];
        }

      virtual ~UniquePointer ()
        {
          deleter(current_ptr);
        }

      T *release ()
        {
          auto ret = current_ptr;
          current_ptr = nullptr;
          return ret;
        }

      void reset (T *ptr) noexcept
        {
          // Saves a copy of the current pointer old_ptr = current_ptr
          auto old_ptr = current_ptr;
          // Overwrites the current pointer with the argument current_ptr = ptr
          current_ptr = ptr;
          // If the old pointer was non-empty, deletes the previously managed object if(old_ptr) get_deleter()(old_ptr).
          if (old_ptr)
            {
              deleter(old_ptr);
            }
        }

      void swap (UniquePointer &other) noexcept
        {
          using std::swap;
          swap(current_ptr, other.current_ptr);
          swap(deleter, other.deleter);
        }

      T *get () const noexcept
        {
          return current_ptr;
        }

      explicit operator bool () const noexcept
        {
          return get() != nullptr;
        }

      const D &get_deleter () const noexcept
        {
          return deleter;
        }

   private:
      T *current_ptr = nullptr;
      D deleter;
   };