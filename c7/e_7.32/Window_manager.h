//
// Created by martin on 17/05/2022.
//

#pragma once

#include "Screen.h"
#include <bits/stdc++.h>

using namespace std;

class Window_manager
{
public:

  using screen_index = vector<Screen>::size_type;

  void clear (screen_index index);

private:

  vector<Screen> screens {Screen {24, 80, ' '}};
};