#include <bits/stdc++.h>
#include "Sales_item.h"

using namespace std;

int main ()
try
  {
    // e 10.29
//    ifstream in_stream { "../text.txt" };
//    istream_iterator<string> isi { in_stream }, eof;
//    vector<string> vs { isi, eof };
//
//    ostream_iterator<string> osi { cout, " " };
//    copy(vs.begin(), vs.end(), osi);

    // e 10.30

//    string s { "1 7 4 9 6 8 4 9 5 8 7 2 9 1" };
//
//    istringstream iss { s };
//
//    istream_iterator<int> isi { iss }, eof;
//    ostream_iterator<int> out { cout, " " };
//
//    vector<int> vi { isi, eof };
//    sort(vi.begin(), vi.end());
//
//    copy(vi.begin(), vi.end(), out);

    // e 10.32

//    string input { "0-201-78111-X 3 20 0-201-78000-X 3 20 0-201-78000-X 3 20" };
//    istringstream iss { input };
//
//    istream_iterator<Sales_item> item_iter { iss }, eof;
//    ostream_iterator<Sales_item> out_iter { cout, "\n" };
//
//    Sales_item sum { *item_iter++ };
//
//    while (item_iter != eof)
//      {
//        if (item_iter->isbn() == sum.isbn())
//          {
//            sum += *item_iter++;
//          }
//        else
//          {
//            out_iter = sum;
//            sum = *item_iter++;
//          }
//      }
//    out_iter = sum;

    // e 10.33

    ifstream in_stream { "../integers.txt" };
    if (!in_stream)
      {
        cerr << "Error opening input file";
        exit(EXIT_FAILURE);
      }

    ofstream out_stream_even { "../even.txt" };
    if (!out_stream_even)
      {
        cerr << "Error opening even output file";
        exit(EXIT_FAILURE);
      }

    ofstream out_stream_odd { "../odd.txt" };
    if (!out_stream_even)
      {
        cerr << "Error opening odd output file";
        exit(EXIT_FAILURE);
      }

    istream_iterator<int> isi { in_stream }, eof;
    ostream_iterator<int> even_out { out_stream_even, "\n" };
    ostream_iterator<int> odd_out { out_stream_odd, " " };

    while (isi != eof)
      {
        if (*isi % 2)
          {
            odd_out = *isi++;
          }
        else
          {
            even_out = *isi++;
          }
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


