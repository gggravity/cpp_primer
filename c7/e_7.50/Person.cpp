//
// Created by martin on 17/05/2022.
//

#include "Person.h"

string Person::name () const
  {
    return m_name;
  }

string Person::address () const
  {
    return m_address;
  }

void Person::set_name (const string &name)
  {
    Person::m_name = name;
  }

void Person::set_address (const string &address)
  {
    Person::m_address = address;
  }

istream &Person::read (istream &is, Person &person)
  {
    string name;
    string address;

    is >> name >> address;

    person.set_name(name);
    person.set_address(address);

    return is;
  }

ostream &Person::print (ostream &os, const Person &person)
  {
    os << "name: " << person.name() << ", address: " << person.address();
    return os;
  }

Person::Person (string n, string a)
    : m_name { std::move(n) },
      m_address { std::move(a) }
  {

  }