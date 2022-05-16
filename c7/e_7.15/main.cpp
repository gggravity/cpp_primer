#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Person
    {
        Person () = default;

        Person (string n, string a);

        string m_name;
        string m_address;

        [[nodiscard]] string name () const;

        [[nodiscard]] string address () const;

        void set_name (const string &m_name);

        void set_address (const string &m_address);

        static istream &read (istream &is, Person &person);

        static ostream &print (ostream &os, const Person &person);
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
    os << "name: " << person.name() << ", address: " << person.address();
    return os;
  }

Person::Person (string n, string a)
    : m_name { std::move(n) },
      m_address { std::move(a) }
  {

  }

int main ()
  {
    Person person1;
    person1.set_name("John Smith");
    person1.set_address("Earth");

    Person person2("Jane Doe", "Mars");

    Person::print(cout, person1);
    cout << endl;
    Person::print(cout, person2);
    cout << endl;

    Person person3;
    Person::read(cin,person3);
    cout << endl;
    Person::print(cout, person3);

    return 0;
  }