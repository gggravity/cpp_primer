#include <bits/stdc++.h>
#include <ostream>

using namespace std;

int sum_int (vector<string> vs)
  {
    int sum { 0 };
    for (auto &s : vs)
      {
        sum += stoi(s);
      }
    return sum;
  }

double sum_double (vector<string> vd)
  {
    double sum { 0 };
    for (auto &s : vd)
      {
        sum += stof(s);
      }
    return sum;
  }

string &to_lower (string &s)
  {
    for (auto &c : s)
      {
        c = char(tolower(c));
      }
    return s;
  }

class Date
      {
      public:
            Date (const string &date)
              {
                string::size_type pos { 0 };

                if (isalpha(date.at(0)))
                  {
                    pos = date.find_first_of(" ,/");
                    auto m = date.substr(0, pos);
                    if (to_lower(m).substr(0, 3) == "jan")
                      {
                        month = 1;
                      }
                    else if (to_lower(m).substr(0, 3) == "feb")
                      {
                        month = 2;
                      }
                    else if (to_lower(m).substr(0, 3) == "mar")
                      {
                        month = 3;
                      }
                    else if (to_lower(m).substr(0, 3) == "apr")
                      {
                        month = 4;
                      }
                    else if (to_lower(m).substr(0, 3) == "may")
                      {
                        month = 5;
                      }
                    else if (to_lower(m).substr(0, 3) == "jun")
                      {
                        month = 6;
                      }
                    else if (to_lower(m).substr(0, 3) == "jul")
                      {
                        month = 7;
                      }
                    else if (to_lower(m).substr(0, 3) == "aug")
                      {
                        month = 8;
                      }
                    else if (to_lower(m).substr(0, 3) == "sep")
                      {
                        month = 9;
                      }
                    else if (to_lower(m).substr(0, 3) == "oct")
                      {
                        month = 10;
                      }
                    else if (to_lower(m).substr(0, 3) == "nov")
                      {
                        month = 11;
                      }
                    else if (to_lower(m).substr(0, 3) == "dec")
                      {
                        month = 12;
                      }
                  }
                else
                  {
                    month = stoi(date.substr(0));
                  }
                pos = date.find_first_of(" ,/") + 1;
                day = stoi(date.substr(pos));

                pos = date.find_first_of(" ,/", pos) + 1;
                year = stoi(date.substr(pos));
              }

            friend ostream &operator<< (ostream &os, const Date &date)
              {
                os << "year: " << date.year << " month: " << date.month << " day: " << date.day;
                return os;
              }

            unsigned year;
            unsigned month;
            unsigned day;
      };

int main (int argc, char *argv[])
try
  {
    // e 9.50

    vector<string> vs { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    vector<string> vd { "1.1", "2.2", "3.3", "4.4", "5.5", "6.6", "7.7", "8.8", "9.9" };
    cout << "the sum is: " << sum_int(vs) << endl;
    cout << "the sum is: " << sum_double(vd) << endl;

    // e 9.51

    Date d1 { "January 1, 1900" };
    Date d2 { "1/1/1900" };
    Date d3 { "Jan 1, 1900" };
    Date d4 { "Feb 12, 1911" };
    Date d5 { "12/13/1912" };
    Date d6 { "July 6, 1999" };

    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;
    cout << "d3: " << d3 << endl;
    cout << "d4: " << d4 << endl;
    cout << "d5: " << d5 << endl;
    cout << "d6: " << d6 << endl;


    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


