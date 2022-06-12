#include <bits/stdc++.h>

using namespace std;

class exceptionType : public exception
   {
   public:
      [[nodiscard]] const char *what () const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
        {
          return "my exception was thrown";
        }
   };

typedef int EXCPTYPE;

int main ()
try
  {
    cout << "try block running..." << endl;

//    throw domain_error("NOOOO!!!!!");

//    throw exceptionType();

    throw 1;

    return 0;
  }
//catch (...)
//  {
//    throw;
//  }
//catch (exceptionType &pet)
//  {
//    cerr << "exceptionType: " << pet.what() << endl;
//    abort();
//  }

catch (EXCPTYPE)
  {
    cout << "EXCPTYPE" << endl;
    throw;
  }
//catch (range_error &error)
//  {
//    cerr << "range_error: " << error.what() << endl;
//    abort();
//  }
//catch (underflow_error &error)
//  {
//    cerr << "underflow_error: " << error.what() << endl;
//    abort();
//  }
//catch (overflow_error &error)
//  {
//    cerr << "overflow_error: " << error.what() << endl;
//    abort();
//  }
//catch (const runtime_error &error)
//  {
//    cerr << "runtime_error: " << error.what() << endl;
//    abort();
//  }
//catch (const bad_cast &error)
//  {
//    cerr << "bad_cast: " << error.what() << endl;
//    abort();
//  }
//catch (const bad_alloc &error)
//  {
//    cerr << "bad_alloc: " << error.what() << endl;
//    abort();
//  }
//catch (const length_error &error)
//  {
//    cerr << "length_error: " << error.what() << endl;
//    abort();
//  }
//catch (const out_of_range &error)
//  {
//    cerr << "out_of_range: " << error.what() << endl;
//    abort();
//  }
//catch (const invalid_argument &error)
//  {
//    cerr << "invalid_argument: " << error.what() << endl;
//    abort();
//  }
//catch (const domain_error &error)
//  {
//    cerr << "domain_error: " << error.what() << endl;
//    abort();
//  }
//catch (const logic_error &error)
//  {
//    cerr << "logic_error: " << error.what() << endl;
//    abort();
//  }
//catch (exception &e)
//  {
//    cerr << "exception: " << e.what() << endl;
//    abort();
//  }

