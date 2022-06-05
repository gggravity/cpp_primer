#pragma once
//
// Created by martin on 05-06-22.
//
#include <bits/stdc++.h>
#include "Screen.h"

using namespace std;

class WindowManager
   {
   public:
      using fixed_screen = Screen<5, 10>;
      using screen_index = vector<fixed_screen>::size_type;

      void clear (screen_index index)
        {
          fixed_screen &s = screens[index];
          s.m_contents = string(s.m_height * s.m_width, ' ');
        }

      void add_screen (const char c)
        {
          screens.emplace_back(fixed_screen { c });
        }

      size_t screen_count ()
        {
          return screens.size();
        }

      void print_screen (ostream &os, size_t i)
        {
          screens[i].display(os);
        }

   private:
      vector<fixed_screen> screens { fixed_screen { } };
   };
