#include <bits/stdc++.h>
#include "Str_blob.h"
#include "Str_blob_ptr.h"
#include "Const_str_blob_ptr.h"

using namespace std;

class str_blob_ptr_ptr
   {
   public:
      str_blob_ptr_ptr (Str_blob_ptr *pointer) : sb_ptr_ptr(pointer)
        {

        }

      Str_blob_ptr *operator-> () const
        {
          return sb_ptr_ptr;
        }

   private:
      Str_blob_ptr *sb_ptr_ptr;
   };

int main ()
try
  {
    Str_blob sb { "A", "B", "C", "D" };

//    cout << sb[1] << endl;

    Str_blob_ptr sbp { sb };

    cout << "dereference: " << ( sbp++ ).dereference() << endl;
    cout << "dereference: " << ( sbp++ ).dereference() << endl;
    cout << "dereference: " << ( sbp++ ).dereference() << endl;
    cout << "dereference: " << ( sbp++ ).dereference() << endl;

    cout << "dereference: " << ( --sbp ).dereference() << endl;
    cout << "dereference: " << ( --sbp ).dereference() << endl;
    cout << "dereference: " << ( --sbp ).dereference() << endl;
    cout << "dereference: " << ( --sbp ).dereference() << endl;

    cout << ( *( &sbp ) )++ << endl;
    cout << ( *( &sbp ) )++ << endl;
    cout << ( *( &sbp ) )++ << endl;
    cout << ( *( &sbp ) )++ << endl;

    cout << "-------------------------" << endl;

    Const_str_blob_ptr csbp { sb };

    cout << *csbp << endl;
    csbp.increment();
    cout << *csbp << endl;
    csbp.increment();
    cout << *csbp << endl;
    csbp.increment();
    cout << *csbp << endl;

    cout << "-------------------------" << endl;

    Str_blob str_blob { "A", "B", "C", "D" };

    Str_blob_ptr str_blob_ptr { str_blob };

    str_blob_ptr_ptr str_blob_ptr_ptr { &str_blob_ptr };
    cout << str_blob_ptr_ptr->dereference() << endl, str_blob_ptr_ptr->increment();
    cout << str_blob_ptr_ptr->dereference() << endl, str_blob_ptr_ptr->increment();
    cout << str_blob_ptr_ptr->dereference() << endl, str_blob_ptr_ptr->increment();
    cout << str_blob_ptr_ptr->dereference() << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
