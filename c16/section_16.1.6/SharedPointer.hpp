#pragma once
//
// Created by martin on 05/06/2022.
//

struct Delete
    {
        template < typename T >
        auto operator() (T *p) const
          {
            delete p;
          }
    };

using namespace std;

template < typename T >
class SharedPointer
   {
   public:
      SharedPointer () :
          current_ptr(nullptr),
          counter(new size_t(1)),
          deleter(deleter)
        { }

      SharedPointer (T *ptr) noexcept :
          current_ptr(ptr),
          deleter(Delete()),
          counter(new size_t(1))
        {
        }

      SharedPointer (T *ptr, const function<void (T *)> &deleter) noexcept :
          current_ptr(ptr),
          deleter(deleter),
          counter(new size_t(1))
        {
        }

      SharedPointer (const SharedPointer &other) :
          current_ptr(other.current_ptr),
          counter(other.counter),
          deleter(other.deleter)
        {
          ++*counter;
        }

      virtual ~SharedPointer ()
        {
          if (--*counter == 0)
            {
              deleter ? deleter(current_ptr) : delete current_ptr;
            }
        }

      auto reset (T *ptr)
        {
          auto old_ptr = current_ptr;
          current_ptr = ptr;
          delete old_ptr;
        }

      auto swap (SharedPointer &other) noexcept
        {
          using std::swap;
          swap(current_ptr, other.current_ptr);
          swap(counter, other.current);
          swap(deleter, other.deleter);
        }

      T *get () const noexcept
        {
          return current_ptr;
        }

      T &operator* () const noexcept
        {
          return *current_ptr;
        }

      T *operator-> () const noexcept
        {
          return current_ptr;
        }

      T &operator[] (size_t index) const
        {
          return current_ptr[index];
        }

      [[nodiscard]] auto use_count () const noexcept
        {
          return *counter;
        }

      [[nodiscard]] bool unique () const noexcept
        {
          return use_count() == 1;
        }

      explicit operator bool () const noexcept
        {
          return get() ? true : false;
        }

   private:
      T *current_ptr = nullptr;
      size_t *counter = nullptr;
      function<void (T *)> deleter = nullptr;
   };