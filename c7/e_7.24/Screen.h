//
// Created by martin on 16/05/2022.
//
#include <bits/stdc++.h>

using namespace std;

class Screen
      {
      public:
            using position = string::size_type;

            Screen () = default;

            Screen (position height, position width);

            Screen (position height, position width, char character);

            [[nodiscard]] char get () const;

            [[nodiscard]] inline char get (position height, position width) const
              {
                position r = height * width;
                return m_contents[r + width];
              }

            Screen &move (position row, position character);

      private:
            position m_height { 0 };
            position m_width { 0 };
            position m_cursor { 0 };
            string m_contents;

      };


