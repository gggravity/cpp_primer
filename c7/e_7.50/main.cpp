#include "Person.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    Person person1;
    person1.set_name ("John Smith");
    person1.set_address ("Earth");

    Person person2 ("Jane Doe", "Mars");

    Person::print (cout, person1);
    cout << endl;
    Person::print (cout, person2);
    cout << endl;

    Person person3;
    Person::read (cin, person3);
    cout << endl;
    Person::print (cout, person3);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
