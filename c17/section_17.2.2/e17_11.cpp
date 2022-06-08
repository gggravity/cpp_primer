#include <bits/stdc++.h>

using namespace std;

template < typename Bitset >
void print (Bitset bitset)
  {
    for (size_t i { 0 } ; i < bitset.size() ; ++i)
      {
        cout << bitset[i];
      }
    cout << endl;
  }

template < size_t Answers >
struct Quiz
    {
        Quiz (const string &name, const string &answers) :
            name(name)
          {
            auto reversed { answers };
            reverse(reversed.begin(), reversed.end());
            _answers = bitset<Answers>(string(reversed));
          }

        void print_result ()
          {
            for (size_t i { 0 } ; i < _answers.size() ; ++i)
              {
                if (_answers.test(i))
                  {
                    cout << name << " answered question " << i + 1 << " correct" << endl;
                  }
                else
                  {
                    cout << name << " answered question " << i + 1 << " wrong" << endl;
                  }
              }
          }

        string name;
        bitset<Answers> _answers;
    };

int main ()
try
  {
    Quiz<10> anna { "Anna", "1110001110" };
    anna.print_result();

    Quiz<20> anna_frank { "Anna Frank", "11100011101110001110" };
    anna_frank.print_result();

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


