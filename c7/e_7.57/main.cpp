#include <bits/stdc++.h>

using namespace std;

class Account
      {
      public:
            Account (string o, double a)
                : owner(o),
                  amount(a)
              {

              };

            void calculate ()
              { amount += amount * interestRate; }

            static double rate ()
              { return interestRate; }

            static void rate (double);

      private:
            string owner;
            double amount { 0 };
            static constexpr int period { 30 };
            double daily_tbl[period];

            static double interestRate;

            static double initRate ();
      };

double Account::initRate ()
  {
    return 0.1;
  }

void Account::rate (double rate)
  {
    interestRate = rate;
  }

double Account::interestRate = initRate();

class Example
      {
            static double rate { 6.5 };
            static const int vecSize { 20 };
//            static vector<double> vec(vecSize);
      };

int main ()
try
  {

//    double Example::rate;
//    vector<double> Example::vec;
    Account act("Name", 123.45);

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
