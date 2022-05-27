#include <bits/stdc++.h>
#include "Message.h"
#include "Folder.h"

using namespace std;

int main ()
try
  {
    Message m1 { "message no 1" };
    Message m2 { "message no 2" };
    Message m3 { "message no 3" };
    Message m4 { "message no 4" };
    Message m5 { "message no 5" };

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
