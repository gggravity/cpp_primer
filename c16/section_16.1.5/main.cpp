#include <bits/stdc++.h>

using namespace std;

//template < typename T = int >
//class NoDefault
//   {
//   public:
//      NoDefault () = delete;
//
//      explicit NoDefault (T t)
//        {
//          secret = t;
//        }
//
//      T get_secret ()
//        {
//          return secret;
//        }
//
//      void set_secret (T t)
//        {
//          secret = t;
//        }
//
//   private:
//      T secret;
//   };
//
//class No_Default
//   {
//   public:
//      No_Default () = delete;
//
//      explicit No_Default (int secret)
//        {
//          m_secret = secret;
//        }
//
//      int get_secret ()
//        {
//          return m_secret;
//        }
//
//      void set_secret (int secret)
//        {
//          m_secret = secret;
//        }
//
//   private:
//      int m_secret;
//   };

//namespace std
//  {
//    extern template class vector<string>;
//    extern template class vector<No_Default>;
//    extern template class vector<NoDefault<string>>;
//    extern template class vector<NoDefault<int>>;
//  }

template < typename T >
class Stack
   {
   public:
      Stack ()
        {
          cout << typeid(T).name() << " stack created" << endl;
        }

   };

void f1 (Stack<char>)
  {
    cout << "f1 running..." << endl;
  }

class Exercise
   {
      Stack<double> sd;
      Stack<double> &rsd = sd;
      Stack<int> si;
   };

int main ()
try
  {
    Stack<char> sc;
    Stack<char> *scp = &sc;
    f1(*scp);
    int iObj = sizeof(Stack<string>);
    cout << iObj << endl;

//    NoDefault<string> no_default { "secret string" };
//    cout << no_default.get_secret() << endl;
//
//    NoDefault<long> secret_number { 53489623423453463 };
//    cout << secret_number.get_secret() << endl;
//
//    cout << "----------------" << endl;
//
//    auto nd = NoDefault(1234);
//
////    vector<NoDefault> v1;
//    vector<NoDefault<int>> v2;
//    v2.emplace_back(1234);
//    cout << v2.begin()->get_secret() << endl;
//
//    cout << "----------------" << endl;
//
//    vector<No_Default> v3;
//    v3.emplace_back(1234);
//    cout << v3.begin()->get_secret() << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


