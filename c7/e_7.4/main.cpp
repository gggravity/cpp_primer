#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string address;
};


int main ()
{

  Person person;
  person.name = "John Smith";
  person.address = "Earth";

  cout << "Name: " << person.name << endl;
  cout << "Address: " << person.address << endl;

  return 0;
}
