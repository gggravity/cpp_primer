#include "Sales_data.h"
#include "employee.h"
#include "string_vector.h"
#include <bits/stdc++.h>

using namespace std;

employee print (employee employee)
{
  cout << employee << endl;
  return std::move (employee);
}

employee employee_factory()
{
  employee e {"Another", "Adresse", "Country", "+23 231 123 123", 9090};

  return std::move (e);
  //    return e;
}

int main()
try
  {
    // e 14.20

    Sales_data sd1 {"XXX-123-QQQ", 12, 123.4};
    Sales_data sd2 {"XXX-123-QQQ", 3, 12.4};
    Sales_data sd3 = sd1 + sd2;

    cout << sd1 << endl;
    cout << sd2 << endl;
    cout << sd3 << endl;
    sd3 += sd2;
    cout << sd3 << endl;

    // 14.21 -> see changes in class.

    Sales_data book {sd1};
    book = string ("book");
    cout << book << endl;
    book = "one more time";
    cout << book << endl;

    // e 14.23

    string_vector sv {"A", "B", "C"};

    cout << sv << endl;

    // e 14.24

    cout << boolalpha;
    cout << "is_move_constructible: " << is_move_constructible_v<employee> << endl;
    cout << "is_trivially_move_constructible: " << is_trivially_move_constructible_v<employee> << endl;
    cout << "is_nothrow_move_constructible: " << is_nothrow_move_constructible_v<employee> << endl;

    employee frank {"Frank", "101 frank town", "USA", "+1 123 123 123", 1};

    cout << frank << endl;

    employee fake_frank {frank};

    cout << fake_frank << endl;

    fake_frank = {"Fake Frank", "101 Fake town", "USA", "+1 123 123 123", 999};

    fake_frank = {"Fake Frank", "101 Fake town", "USA", "+1 123 123 123", 999};

    auto e {employee_factory()};

    cout << e << endl;

    auto e_frank = print (fake_frank);

    print (e_frank);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
