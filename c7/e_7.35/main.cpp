#include <bits/stdc++.h>

using namespace std;

typedef string Type;

Type initVal ();

class Exercise
      {
      public:
//            typedef double Type;

            Type setVal (Type type)
              {
                cout << "Type: " << type << endl;
                return {};
              }

            Type initVal ()
              {
                return {};
              }

      private:
            int val;
      };

int main ()
try
  {
    Exercise exercise;
//    exercise.setVal(1.1f);
    exercise.setVal("1.1f");

    cout << "Exercise 7.35" << endl;
    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
