#include <bits/stdc++.h>

using namespace std;

struct destination
    {
    };
struct connection
    {
    };

connection connect (destination *)
  {
    cout << "connecting..." << endl;
    return {};
  }

void disconnect (connection)
  {
    cout << "disconnecting..." << endl;
  }

void end_connection (connection *p)
  {
    disconnect(*p);
  }

void f (destination &d)
  {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
  }

void f2 (destination &d)
  {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [] (connection *p)
      {
          cout << "... with lambda... ";
          disconnect(*p);
      });
  }

int main ()
try
  {
    destination d;

    f(d);
    f2(d);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


