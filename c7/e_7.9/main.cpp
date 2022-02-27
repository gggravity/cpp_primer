#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string address;
    [[nodiscard]] string getName() const;
    [[nodiscard]] string getAddress() const;
    static istream &read(istream &is, Person &person);
    static ostream &print(ostream &os, const Person &person);
};

string Person::getName () const
{
  return name;
}

string Person::getAddress () const
{
  return address;
}
istream &Person::read (istream &is, Person &person)
{
  is >> person.name >> person.address;
  return is;
}
ostream &Person::print (ostream &os, const Person &person)
{
  os << "name: " << person.name << ", address: " << person.address;
  return os;
}

int main ()
{

  Person person;
  person.name = "John Smith";
  person.address = "Earth";

  Person::print(cout, person);

  return 0;
}