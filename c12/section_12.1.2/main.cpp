#include <bits/stdc++.h>

using namespace std;

bool b()
{
  int *p = new int;
  // ... an int will leak every time the function is run.
  return p;
}

vector<int> *factory()
{
  auto v = new vector<int>;
  return v;
}

vector<int> *read (vector<int> *v)
{
  istringstream iss {"1 2 3 4 5 6 7 8 9"};
  int i;

  while (iss >> i)
    {
      v->push_back (i);
    }
  return v;
}

void print (vector<int> *v)
{
  for (auto &i : *v)
    {
      cout << i << " ";
    }
  cout << endl;
}

shared_ptr<vector<int>> factory_shared_ptr()
{
  auto v = make_shared<vector<int>>();
  return v;
}

shared_ptr<vector<int>> read_shared_ptr (shared_ptr<vector<int>> v)
{
  istringstream iss {"1 2 3 4 5 6 7 8 9"};
  int i;

  while (iss >> i)
    {
      v->push_back (i);
    }
  return v;
}

void print_shared_ptr (const shared_ptr<vector<int>> v)
{
  for (auto &i : *v)
    {
      cout << i << " ";
    }
  cout << endl;
}

int main()
try
  {
    // e 12.6

    auto v = factory();
    v = read (v);
    print (v);
    delete v;

    cout << "-------------" << endl;

    // e 12.7

    auto v_shared_ptr = factory_shared_ptr();
    v_shared_ptr = read_shared_ptr (v_shared_ptr);
    print_shared_ptr (v_shared_ptr);

    cout << "use_count: " << v_shared_ptr.use_count() << endl;

    // e 12.8

    //    bool b ()
    //      {
    //        int *p = new int;
    //        // ... an int will leak every time the function is run.
    //        return p;
    //      }

    // e 12.9

    int *q = new int (42), *r = new int (100);                     // two new int are allocated on the heap.
    r = q;                                                         // *r's int will leak.
    auto q2 = make_shared<int> (42), r2 = make_shared<int> (100);  // same with smart pointers
    r2 = q2;                                                       // make_shared<int>(100) will be deallocated.

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
