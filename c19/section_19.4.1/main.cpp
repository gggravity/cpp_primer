#include "SalesData.hpp"
#include <bits/stdc++.h>

using namespace std;

class Screen
{
public:

  typedef string::size_type pos;

  [[nodiscard]] char get_cursor() const { return contents[cursor]; }

  [[nodiscard]] char get() const;

  [[nodiscard]] char get (pos ht, pos wd) const;

  static const string Screen::*data() { return &Screen::contents; }

private:

  string contents {"0001000"};
  pos cursor;
  pos height, width;
};

int main()
{
  Screen myScreen;

  const string Screen::*pdata {Screen::data()};

  auto s {myScreen.*pdata};

  cout << s << endl;

  SalesData mySalesData {"123-QQQ", 1, 1};

  const string SalesData::*ptr_isbn {SalesData::data()};

  auto isbn {mySalesData.*ptr_isbn};

  cout << isbn << endl;

  return 0;
}
