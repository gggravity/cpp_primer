#pragma once

#include <bits/stdc++.h>

using namespace std;

using position = string::size_type;

template <position height, position width> class Screen
{
public:

  Screen()
      : m_height {height}, m_width {width}, m_contents {string (height * width, ' ')}
        // Fills the string with n consecutive copies of character c.

  {
  }

  Screen (char character)
      : m_height {height}, m_width {width}, m_contents {string (height * width, character)}
        // Fills the string with n consecutive copies of character c.
  {
  }

  [[nodiscard]] inline char get() const
  {
    position r = height * width;
    return m_contents[r + width];
  }

  Screen &move (position row, position characters)
  {
    position r = row * m_width;
    m_cursor = r + characters;
    return *this;
  }

  Screen &set (char c)
  {
    m_contents[m_cursor] = c;
    return *this;
  }

  Screen &set (position r, position col, char ch)
  {
    m_contents[r * m_width + col] = ch;
    return *this;
  }

  Screen &display (ostream &os)
  {
    do_display (os);
    return *this;
  }

  const Screen &display (ostream &os) const
  {
    do_display (os);
    return *this;
  }

  [[nodiscard]] position size() const { return m_height * m_width; }

private:

  position m_height {0};
  position m_width {0};
  position m_cursor {0};
  string m_contents;

  void do_display (ostream &os) const
  {
    for (size_t i {0}; i < size(); ++i)
      {
        if (i % m_width == 0)
          {
            os << endl;
          }
        os << m_contents[i] << " ";
      }
  }

  // friends

  friend class WindowManager;
};