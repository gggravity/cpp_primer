#include <iostream>
#include <string>

using namespace std;

struct Person
    {
        string m_name;
        string m_address;

        [[nodiscard]] string name () const;

        [[nodiscard]] string address () const;

        static istream &read (istream &is, Person &person);

        static ostream &print (ostream &os, const Person &person);

        void set_name (const string &name);

        void set_address (const string &address);
    };

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
    os << "{ name: \"" << person.name() << "\", address: \"" << person.address() << "\" }";
    return os;
  }

int main ()
  {

    Person person;
    person.set_name("John Smith");
    person.set_address("Earth");

    Person::print(cout, person);

    return 0;
  }

