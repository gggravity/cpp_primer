//
// Created by martin on 27-05-22.
//

#include "String.h"

allocator<char> String::alloc;

String::String (initializer_list<char> initializer_list) :
    elements(nullptr),
    first_free(nullptr),
    cap(nullptr)
  {
    for (auto &s : initializer_list)
      {
        push_back(s);
      }
  }

String::String (const string &string)
  {
    for (auto &c : string)
      {
        push_back(c);
      }
  }

String::String (const char *c_string)
  {
    auto ptr = c_string;
    while (*ptr != '\0')
      {
        push_back(*ptr++);
      }
  }

String::String (const String &other)
  {
    cout << "copy constructor called..." << endl;
    auto new_data = allocate_and_copy(other.begin(), other.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
  }

String &String::operator= (const String &other)
  {
    cout << "copy assignment operator called..." << endl;
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

String &String::operator= (const char *other)
  {
    cout << "copy assignment operator called..." << endl;
    *this = String(other);
    return *this;
  }

String::~String ()
  {
    free();
  }

void String::push_back (const char &c)
  {
    check_and_allocate();
    alloc.construct(first_free++, c);
  }

size_t String::size () const
  {
    return first_free - elements;
  }

size_t String::capacity () const
  {
    return cap - elements;
  }

void String::reserve (size_t n)
  {
    reallocate(n);
  }

char *String::begin () const
  {
    return elements;
  }

char *String::end () const
  {
    return first_free;
  }

void String::check_and_allocate ()
  {
    if (size() == capacity())
      {
        reallocate();
      }
  }

pair<char *, char *> String::allocate_and_copy (const char *begin, const char *end)
  {
    auto data = alloc.allocate(end - begin);
    return { data, uninitialized_copy(begin, end, data) };
  }

void String::free ()
  {
    if (elements)
      {
        for (auto ptr = first_free ; ptr != elements ; /* empty */)
          {
            alloc.destroy(--ptr);
          }
        alloc.deallocate(elements, cap - elements);
      }
  }

void String::reallocate (size_t new_capacity)
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
        alloc.construct(destination++, *element++);
      }

    free();
    elements = new_data;
    first_free = destination;
    cap = elements + new_capacity;
  }

ostream &operator<< (ostream &os, const String &string)
  {
    for (auto &c : string)
      {
        cout << c;
      }
    return os;
  }

String &String::operator= (String &&other) noexcept
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

String::String (String &&other) noexcept :
    elements(other.elements),
    first_free(other.first_free),
    cap(other.cap)
  {
    cout << "move constructor called..." << endl;
    other.elements = other.first_free = other.cap = nullptr;
  }

bool operator== (const String &lhs, const String &rhs)
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

    for (size_t i { 0 } ; *ptr_lhs != '\0' && i < lhs.size() ; ptr_lhs++, ptr_rhs++)
      {
        if (*ptr_lhs != *ptr_rhs)
          {
            return false;
          }
      }

    return true;
  }

bool operator!= (const String &lhs, const String &rhs)
  {
    return !( rhs == lhs );
  }
