#include <bits/stdc++.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace std;

boost::uuids::random_generator uuid_generator;

struct numbered
{
  numbered() : uuid (uuid_generator()) { cout << "constructor called" << endl; };

  numbered (const numbered &) : uuid (uuid_generator()) { cout << "copy constructor called" << endl; };

  boost::uuids::uuid uuid;
};

void f (const numbered &s) { cout << s.uuid << endl; }

int main()
try
  {
    numbered a, b = a, c = b;
    f (a);
    f (b);
    f (c);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
