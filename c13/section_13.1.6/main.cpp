#include <bits/stdc++.h>

#include <ostream>
#include <utility>

using namespace std;

struct employee
{
  employee()
      : name ("Unknown"), id (++employee::current_id) {

                          };

  explicit employee (string name)
      : name (move (name)), id (++employee::current_id) {

                            };

  string name;
  int id;
  static int current_id;

  friend ostream &operator<< (ostream &os, const employee &employee)
  {
    os << "name: " << employee.name << ", id: " << employee.id;
    return os;
  }
};

int employee::current_id {1000};

int main()
try
  {

    vector<employee> employees;
    employees.emplace_back ("Jack");
    employees.emplace_back ("Jill");
    employees.emplace_back();
    employees.emplace_back ("Anna");
    employees.emplace_back ("Arn");

    employee e1 {"Gretha"};
    employee e2 {"Benjamin"};

    cout << e1 << endl;
    cout << e2 << endl;
    e1 = e2;
    cout << e1 << endl;
    employee e3 {e2};
    cout << e3 << endl;

    for (auto &employee : employees)
      {
        cout << employee << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
