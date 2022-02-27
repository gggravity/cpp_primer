#include <iostream>
#include <string>

using namespace std;

class Person {
 public:
  Person () = default;
  Person (const string &n, const string &a)
      : _name (n), _address (a)
  {}

  [[nodiscard]] string getName () const;
  void setName (const string &name);
  void setAddress (const string &address);
  const string getName () { return _name; };
  const string getAddress() { return _address; };
  [[nodiscard]] string getAddress () const;
  static istream &read (istream &is, Person &person);
  static ostream &print (ostream &os, const Person &person);
 private:
  string _name;
  string _address;
};

string Person::getName () const
{
  return _name;
}

string Person::getAddress () const
{
  return _address;
}
istream &Person::read (istream &is, Person &person)
{
  string name;
  string address;
  is >> name >> address;
  person.setName (name);
  person.setAddress (address);

  return is;
}
ostream &Person::print (ostream &os, const Person &person)
{
  os << "name: " << person.getName() << ", address: " << person.getAddress();
  return os;
}
void Person::setName (const string &name)
{
  _name = name;
}
void Person::setAddress (const string &address)
{
  _address = address;
}

int main ()
{

  Person person1;
  person1.setName ("John Smith");
  person1.setAddress ("Earth");

  Person person2 ("Jane Doe", "Mars");

  Person::print (cout, person1);
  cout << endl;
  Person::print (cout, person2);

  return 0;
}