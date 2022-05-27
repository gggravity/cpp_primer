#include <bits/stdc++.h>
#include "message.h"
#include "folder.h"

using namespace std;

int main ()
try
  {
    message m1 { "message no 1" };
    message m2 { "message no 2" };
    message m3 { "message no 3" };
    message m4 { "message no 4" };
    message m5 { "message no 5" };
    message m6 { "message no 6" };

    folder folder1;
    folder folder2;

    folder1.insert(m1);
    folder1.insert(m2);
    folder1.insert(m3);

    folder2.insert(m4);
    folder2.insert(m5);
    folder2.insert(m6);

    folder1.print();
    folder2.print();



    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
