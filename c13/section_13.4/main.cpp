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
    Message m6 { "message no 6" };

    Folder folder1;
    Folder folder2;

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
