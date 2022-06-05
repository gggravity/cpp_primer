#include <bits/stdc++.h>
#include "Blob.h"
#include "BlobPtr.h"
#include "Screen.h"
#include "WindowManager.h"
#include "Vector.h"

using namespace std;

//template < typename elemType >
//class ListItem;
//
///*
//template < typename elemType >
//class List
//   {
//   public:
//      List<elemType> ();
//
//      List<elemType> (const List<elemType> &);
//
//      List<elemType> &operator= (const List<elemType> &);
//
//      ~List ();
//
//      void insert (ListItem *ptr, elemType value);
//
//   private:
//      ListItem *front;
//      ListItem *end;
//
//   };
//*/
//template < typename elemType >
//class List
//   {
//   public:
//      List () = default;
//
//      List (const List<elemType> &elem_list)
//        { };
//
//      List &operator= (const List<elemType> &) = default;
//
//      ~List () = default;;
//
//      void insert (ListItem<elemType> *ptr, elemType value)
//        { };
//
//   private:
//      ListItem<elemType> *front;
//      ListItem<elemType> *end;
//
//   };

int main ()
try
  {
//    Blob<string> blob_1 { string("ABC"), string("QWERTY"), string("123456789") };
//    Blob<string> blob_2 { "ABC", "QWERTY", "123456789" };
//    Blob<int> blob_3  { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//    cout << blob_1 << endl;
//    cout << blob_2 << endl;
//    cout << blob_3 << endl;
//
//    BlobPtr<string> blob_ptr_1 { blob_1 };
//    BlobPtr<string> blob_ptr_2 { blob_2 };
//    BlobPtr<int> blob_ptr_3 { blob_3 };
//
//    cout << blob_ptr_1.dereference() << endl, blob_ptr_1.increment();
//    cout << blob_ptr_1.dereference() << endl, blob_ptr_1.increment();
//    cout << blob_ptr_1.dereference() << endl, blob_ptr_1.increment();
//
//    cout << blob_ptr_2.dereference() << endl, blob_ptr_2.increment();
//    cout << blob_ptr_2.dereference() << endl, blob_ptr_2.increment();
//    cout << blob_ptr_2.dereference() << endl, blob_ptr_2.increment();
//
//    for (int i = 0 ; i < 9 ; ++i)
//      {
//        cout << blob_ptr_3.dereference() << endl, blob_ptr_3.increment();
//      }

//    Screen<5, 5> screen('X');
//
//    screen.display(cout);
//    cout << endl;
//
//    screen.move(1, 2).set('#').display(cout);
//    cout << endl;
//
//    cout << "size: " << screen.size() << endl;
//
//    WindowManager window_manager;
//
//    window_manager.add_screen('1');
//    window_manager.add_screen('2');
//    window_manager.add_screen('3');
//
//    cout << window_manager.screen_count() << endl;
//
//    window_manager.print_screen(cout, 3);

    Vector<string> string_vector { "A", "B", "C" };

    for (auto &s : string_vector)
      {
        cout << s << " ";
      }

    cout << endl;

    Vector<int> int_vector { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (auto &i : int_vector)
      {
        cout << i << " ";
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


