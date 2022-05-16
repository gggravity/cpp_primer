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
    this->contents = string(number_of_blanks, ' ')
  }

  char get () const
  { return contents[curser]; }

  inline char get(position height, position width) const;

  Screen &move(position row, position character);

 private:
  position height{0};
  position width{0};
  position curser{0};
  string contents;

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

int main ()
{
  Screen screen;
  char ch = screen.get();
  ch = screen.get(0,0);

  return 0;
}
