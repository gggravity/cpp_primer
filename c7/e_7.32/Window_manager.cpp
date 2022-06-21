//
// Created by martin on 17/05/2022.
//

#include "Window_manager.h"

void Window_manager::clear (Window_manager::screen_index index)
{
  Screen &s = screens[index];
  s.m_contents = string (s.m_height * s.m_width, ' ');
}