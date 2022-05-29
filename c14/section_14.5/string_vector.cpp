//
// Created by martin on 27-05-22.
//

#include "string_vector.h"

allocator<string> string_vector::alloc;

string_vector::string_vector () :
    elements(nullptr),
    first_free(nullptr),
    cap(nullptr)
  {

  }

string_vector::string_vector (initializer_list<string> initializer_list) :
    elements(nullptr),
    first_free(nullptr),
    cap(nullptr)
  {
    for (auto &s : initializer_list)
      {
        push_back(s);
      }
  }

string_vector::string_vector (const string_vector &other)
  {
    auto new_data = allocate_and_copy(other.begin(), other.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
  }

string_vector &string_vector::operator= (const string_vector &other)
  {
    if (this != &other)
      {
        auto data = allocate_and_copy(other.begin(), other.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
      }
    return *this;
  }

string_vector &string_vector::operator= (string_vector &&other) noexcept
  {
    cout << "move assignment operator called..." << endl;
    if (this != &other)
      {
        elements = other.elements;
        first_free = other.first_free;
        cap = other.cap;
        other.elements = other.first_free = other.cap = nullptr;
      }
    return *this;
  }

string_vector::string_vector (string_vector &&other) noexcept :
    elements(other.elements),
    first_free(other.first_free),
    cap(other.cap)
  {
    cout << "move constructor called..." << endl;
    other.elements = other.first_free = other.cap = nullptr;
  }

string_vector::~string_vector ()
  {
    free();
  }

void string_vector::push_back (const string &string)
  {
    check_and_allocate();
    alloc.construct(first_free++, string);
  }

size_t string_vector::size () const
  {
    return first_free - elements;
  }

size_t string_vector::capacity () const
  {
    return cap - elements;
  }

void string_vector::reserve (size_t n)
  {
    reallocate(n);
  }

string *string_vector::begin () const
  {
    return elements;
  }

string *string_vector::end () const
  {
    return first_free;
  }

void string_vector::check_and_allocate ()
  {
    if (size() == capacity())
      {
        reallocate();
      }
  }

pair<string *, string *> string_vector::allocate_and_copy (const string *begin, const string *end)
  {
    auto data = alloc.allocate(end - begin);
    return { data, uninitialized_copy(begin, end, data) };
  }

void string_vector::free ()
  {
    if (elements)
      {
//        for (auto ptr = first_free ; ptr != elements ; /* empty */)
//          {
//            alloc.destroy(--ptr);
//          }
        for_each(elements, first_free, [] (string &s)
          {
              alloc.destroy(&s);
          });
        alloc.deallocate(elements, cap - elements);
      }
  }

void string_vector::reallocate (size_t new_capacity)
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

ostream &operator<< (ostream &os, const string_vector &vector)
  {
    for (auto &s : vector)
      {
        os << "\"" << s << "\"" << " ";
      }
    return os;
  }

bool operator== (const string_vector &lhs, const string_vector &rhs)
  {
    if (&lhs == &rhs)
      {
        return true;
      }

    if (lhs.size() != rhs.size())
      {
        return false;
      }

    auto ptr_lhs = lhs.elements;
    auto ptr_rhs = rhs.elements;

    for (size_t i { 0 } ;  *ptr_lhs != "\0" && i < lhs.size() ; ptr_lhs++, ptr_rhs++)
      {
        if (*ptr_lhs != *ptr_rhs)
          {
            return false;
          }
      }

    return true;
  }

bool operator!= (const string_vector &lhs, const string_vector &rhs)
  {
    return !( rhs == lhs );
  }

string &string_vector::operator[] (size_t n)
  {
    return elements[n];
  }

const string &string_vector::operator[] (size_t n) const
  {
    return elements[n];
  }

