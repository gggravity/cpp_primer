#include <iostream>

using namespace std;

class Screen {
 public:
  using position = string::size_type;

  Screen () = default;

  Screen (position height, position width, char character)
  {
    this->height = height;
    this->width = width;
    this->contents = string (height * width, character);
  }

  Screen (position height, position width, int number_of_blanks)
  {
    this->height = height;
    this->width = width;
    this->contents = string (number_of_blanks, ' ');
  }

  char get () const
  { return contents[curser]; }

  inline char get (position height, position width) const;

  Screen &move (position row, position character);

  Screen &set (char);
  Screen &set (position r, position col, char ch);

  Screen &display (ostream &os)
  {
    do_display(os);
    return *this;
  }
  const Screen &display (ostream &os) const
  {
    do_display(os);
    return *this;
  }


 private:
  position height{0};
  position width{0};
  position curser{0};
  string contents;

  void do_display(ostream &os) const
  {
    os << contents;
  }

};

char Screen::get (Screen::position height, Screen::position width) const
{
  position r = height * width;
  return contents[r + width];
}
Screen &Screen::move (Screen::position row, Screen::position character)
{
  position r = row * width;
  curser = r + character;
  return *this;
}
Screen &Screen::set (char c)
{
  contents[curser] = c;
  return *this;
}
Screen &Screen::set (Screen::position r, Screen::position col, char ch)
{
  contents[r * width + col] = ch;
  return *this;
}

int main ()
{
  Screen myScreen(5,5, 'X');
  myScreen.move (4,0).set ('#').display (cout);
  cout << "\n";
  myScreen.display (cout);
  cout << "\n";

  return 0;
}
