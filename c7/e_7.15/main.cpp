#include <iostream>
#include <string>

using namespace std;

struct Person {
    Person () = default;
    Person (const string &n, const string &a)
        : name (n), address (a)
    {}
    string name;
    string address;
    [[nodiscard]] string getName () const;
    [[nodiscard]] string getAddress () const;
    static istream &read (istream &is, Person &person);
    static ostream &print (ostream &os, const Person &person);
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

  Person person1;
  person1.name = "John Smith";
  person1.address = "Earth";

  Person person2("Jane Doe", "Mars");

  Person::print (cout, person1);
  cout << endl;
  Person::print (cout, person2);

  return 0;
}