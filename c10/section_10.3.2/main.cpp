#include <bits/stdc++.h>

using namespace std;

void eliminate_dups (vector<string> &words)
  {
    sort(words.begin(), words.end());
    auto end_iter { unique(words.begin(), words.end()) };
    words.erase(end_iter, words.end());
  }

int main (int argc, char *argv[])
try
  {
//    // e 10.14
//    auto sum = [] (int a, int b)
//      {
//          return a + b;
//      };
//
//    cout << "sum: " << sum(1, 2) << endl;
//
//    // e 10.15
//
//    int cap { 12 };
//
//    auto sum_cap = [cap] (int a)
//      {
//          return cap + a;
//      };
//
//    cout << "sum_cap: " << sum_cap(8) << endl;
//
//    // e 10.16
//
//    vector<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
//    vector<string>::size_type sz { 5 };
//    auto biggies = [&words, sz] ()
//      {
//          eliminate_dups(words);
//          stable_sort(words.begin(), words.end(), [] (const string &a, const string &b)
//            {
//                return a.size() < b.size();
//            });
//          auto wc = find_if(words.begin(), words.end(), [sz] (const string &a)
//            {
//                return a.size() >= sz;
//            });
//          auto count { words.end() - wc };
//
//          cout << count << " " << ( count > 1 ? "words" : "word" ) << " of length " << sz << " or longer"
//               << ", the words are: ";
//
//          for_each(wc, words.end(), [] (const string &s)
//            {
//                cout << s << " ";
//            });
//          cout << endl;
//      };
//
//    biggies();

    // e 10.18

//    vector<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
//    vector<string>::size_type sz { 5 };
//    auto biggies = [&words, sz] ()
//      {
//          eliminate_dups(words);
//          stable_sort(words.begin(), words.end(), [] (const string &a, const string &b)
//            {
//                return a.size() < b.size();
//            });
//
//          auto end_iter = partition(words.begin(), words.end(), [sz] (const string &a)
//            {
//                return a.size() >= sz;
//            });
//          auto count { distance(words.begin(), end_iter) };
//
//          cout << count << " " << ( count > 1 ? "words" : "word" ) << " of length " << sz << " or longer"
//               << ", the words are: ";
//
//          for_each(words.begin(), end_iter, [] (const string &s)
//            {
//                cout << s << " ";
//            });
//          cout << endl;
//      };
//
//    biggies();

    // e 10.19

    vector<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    vector<string>::size_type sz { 5 };
    auto biggies = [&words, sz] ()
      {
          eliminate_dups(words);

          stable_sort(words.begin(), words.end(), [] (const string &a, const string &b)
            {
                return a.size() < b.size();
            });

          auto end_iter = stable_partition(words.begin(), words.end(), [sz] (const string &a)
            {
                return a.size() >= sz;
            });

          auto count { distance(words.begin(), end_iter) };

          cout << count << " " << ( count > 1 ? "words" : "word" ) << " of length " << sz << " or longer"
               << ", the words are: ";

          for_each(words.begin(), end_iter, [] (const string &s)
            {
                cout << s << " ";
            });

          cout << endl;
      };

    biggies();

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


