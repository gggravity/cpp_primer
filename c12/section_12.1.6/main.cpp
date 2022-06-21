#include "Const_str_blob_ptr.h"
#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    // e 12.20

    size_t size {0};
    ifstream ifs {"../file.txt"};
    if (! ifs)
      {
        cout << "can't open file";
        exit (EXIT_FAILURE);
      }

    Str_blob bob;
    for (string line; getline (ifs, line);)
      {
        istringstream iss {line};
        for (string word; iss >> word;)
          {
            bob.push_back (word);
            size++;
          }
      }

    Str_blob_ptr str_blob_ptr {bob};

    for (int i {0}; i < size; str_blob_ptr.increment(), ++i)
      {
        cout << i << ": " << str_blob_ptr.dereference() << endl;
      }

    // e 12.21

    // old version is better, much easier to read.

    // e 12.22

    const Str_blob blob {"1", "2", "3", "4"};
    Const_str_blob_ptr c_sb_ptr {blob};

    for (int i {0}; i < blob.size(); c_sb_ptr.increment(), ++i)
      {
        cout << "const version -> " << i << ": " << c_sb_ptr.dereference() << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
