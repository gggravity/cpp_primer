//
// Created by martin on 16/05/2022.
//

#include "Screen.h"

Screen::Screen (Screen::position height, Screen::position width)
    : m_height { height },
      m_width { width },
      m_contents { string(height * width, ' ') } // Fills the string with n consecutive copies of character c.

  {

  }

Screen::Screen (Screen::position height, Screen::position width, char character)
    : m_height { height },
      m_width { width },
      m_contents { string(height * width, character) } // Fills the string with n consecutive copies of character c.
  {

  }

char Screen::get () const
  {
    return m_contents[m_cursor];
  }

// Helper functions

//inline char Screen::get (Screen::position height, Screen::position width) const


Screen &Screen::move (Screen::position row, Screen::position characters)
  {
    position r = row * m_width;
    m_cursor = r + characters;
    return *this;
  }
