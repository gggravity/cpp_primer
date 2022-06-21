#include "SalesData.hpp"
#include <bits/stdc++.h>

using namespace std;

class Screen
{
public:

  typedef string::size_type pos;

  [[nodiscard]] char get_cursor() const { return contents[cursor]; }

  [[nodiscard]] char get() const
  {
    cout << "Running get()" << endl;
    return 'X';
  }

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

  auto pmf {&Screen::get_cursor};
  pmf = &Screen::get;

  cout << (myScreen.*pmf)() << endl;

  using SD_PTR = double (SalesData::*)() const;

  auto sd_ptr {&SalesData::avg_price};

  SD_PTR sd_ptr2 {&SalesData::avg_price};

  using S_PTR = char (Screen::*)() const;

  using S_POS_PTR = char (Screen::*) (Screen::pos, Screen::pos) const;

  return 0;
}
