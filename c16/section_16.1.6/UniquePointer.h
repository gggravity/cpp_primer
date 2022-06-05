#pragma once
//
// Created by martin on 05/06/2022.
//

#include <ostream>

using namespace std;

class DebugDelete
   {
   public:
      explicit DebugDelete (ostream &os = cerr) :
          os(os)
        {

        }

      template < typename T >
      void operator() (T *p) const
        {
          os << "deleting pointer at: " << p << endl;
          delete p;
        }

   private:
      ostream &os;
   };

template < typename T, typename D = DebugDelete >
class UniquePointer
   {
   public:
      UniquePointer (T *ptr, const D &d = D()) :
          current_ptr(ptr),
          deleter(deleter)
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

      T &operator* ()
        {
          if (current_ptr == nullptr)
            {
              cerr << "No pointer at address" << endl;
              exit(EXIT_FAILURE);
            }

          return *current_ptr;
        }

      friend ostream &operator<< (ostream &os, const UniquePointer &unique_pointer)
        {
          os << unique_pointer.current_ptr;
          return os;
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
              get_deleter()(old_ptr);
            }
        }

      void swap (UniquePointer &other) noexcept
        {
//          auto temp = current_ptr;
//          current_ptr = other.current_ptr;
//          other.current_ptr = temp;
          using std::swap;
          swap(current_ptr, other.current_ptr);
//          swap(deleter, other.deleter);
        }

      T *get () const noexcept
        {
          return current_ptr;
        }

      D get_deleter ()
        {
          return deleter;
        }

   private:
      T *current_ptr;
      D deleter;
   };