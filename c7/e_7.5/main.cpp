#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string address;
    string getName() const;
    string getAddress() const;
};

string Person::getName () const
{
  return name;
}

string Person::getAddress () const
{
  return address;
}


int main ()
{

  Person person;
  person.name = "John Smith";
  person.address = "Earth";

  cout << "Name: " << person.getName() << endl;
  cout << "Address: " << person.getAddress() << endl;

  return 0;
}