#include <bits/stdc++.h>
#include "Blob.h"
#include "BlobPtr.h"

using namespace std;

int main ()
try
  {
    Blob<string> blob {"A", "B", "C"};

//    BlobPtr<string> blob_ptr {blob};



    return 0;
  }
catch (range_error &error)
  {
    cerr << "range_error: " << error.what() << endl;
    abort();
  }
catch (underflow_error &error)
  {
    cerr << "underflow_error: " << error.what() << endl;
    abort();
  }
catch (overflow_error &error)
  {
    cerr << "overflow_error: " << error.what() << endl;
    abort();
  }
catch (const runtime_error &error)
  {
    cerr << "runtime_error: " << error.what() << endl;
    abort();
  }
catch (const bad_cast &error)
  {
    cerr << "bad_cast: " << error.what() << endl;
    abort();
  }
catch (const bad_alloc &error)
  {
    cerr << "bad_alloc: " << error.what() << endl;
    abort();
  }
catch (const length_error &error)
  {
    cerr << "length_error: " << error.what() << endl;
    abort();
  }
catch (const out_of_range &error)
  {
    cerr << "out_of_range: " << error.what() << endl;
    abort();
  }
catch (const invalid_argument &error)
  {
    cerr << "invalid_argument: " << error.what() << endl;
    abort();
  }
catch (const domain_error &error)
  {
    cerr << "domain_error: " << error.what() << endl;
    abort();
  }
catch (const logic_error &error)
  {
    cerr << "logic_error: " << error.what() << endl;
    abort();
  }
catch (exception &e)
  {
    cerr << "exception: " << e.what() << endl;
    abort();
  }

