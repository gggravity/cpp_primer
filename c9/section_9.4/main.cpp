#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
try
  {
//    vector<int> v;
//    auto capacity { v.capacity() };
//
//    for (int i { 1 } ; i < 1000000 ; ++i)
//      {
//        if (v.capacity() != capacity)
//          {
//            cout << "capacity: " << v.capacity() << endl;
//            capacity = v.capacity();
//          }
//        v.push_back(0);
//      }

    vector<string> svec;
    svec.reserve(1024);
    string word;
    auto capacity = svec.capacity();

    for (int i { 0 } ; i < 1048 ; ++i)
      {
        istringstream iss { to_string(i) };
        iss >> word;
        svec.push_back(word);

        if (svec.capacity() != capacity)
          {
            cout << "capacity: " << svec.capacity() << endl;
            capacity = svec.capacity();
          }
      }

    cout << svec.capacity() << endl;

    svec.resize(svec.size() + svec.size() / 2);

    cout << svec.capacity() << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }














