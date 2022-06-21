#include "folder.h"
#include "message.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    message m1 {"message no 1"};
    message m2 {"message no 2"};
    message m3 {"message no 3"};
    message m4 {"message no 4"};
    message m5 {"message no 5"};
    message m6 {"message no 6"};
    message m7 {"message no 7"};

    folder folder1 {"secret folder"};
    folder folder2;

    folder1.insert (m1);
    folder1.insert (m2);
    folder1.insert (m3);

    folder2.insert (m4);
    folder2.insert (m5);
    folder2.insert (m6);

    m1.save (folder2);

    folder1.print_content();
    folder2.print_content();

    cout << "folders: ", m1.print_folders(), cout << endl;
    cout << "folders: ", m2.print_folders(), cout << endl;
    cout << "folders: ", m7.print_folders(), cout << endl;

    folder folder3 {"folder 3"};
    folder folder4 (folder3);

    cout << folder3 << endl;
    cout << folder4 << endl;

    folder2.print_content();
    m6.remove (folder2);
    folder2.print_content();

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
