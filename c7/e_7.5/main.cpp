#include <iostream>
#include <string>

using namespace std;

struct Person
    {
        string m_name;
        string m_address;

        [[nodiscard]] string name () const;

        [[nodiscard]] string address () const;

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

int main ()
  {
    Person person;
    person.set_name("John Smith");
    person.set_address("Earth");

    cout << "Name: " << person.name() << endl;
    cout << "Address: " << person.address() << endl;

    return 0;
  }

