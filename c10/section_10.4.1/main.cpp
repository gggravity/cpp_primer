#include <bits/stdc++.h>

using namespace std;

int main()
try
  {
    vector<string> words {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    vector<string> u;

    sort (words.begin(), words.end());
    unique_copy (words.begin(), words.end(), inserter (u, u.end()));
    for (auto &w : u)
      {
        cout << w << " ";
      }
    cout << endl;

    vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi1;
    list<int> vi2;
    vector<int> vi3;

    copy (vi.begin(), vi.end(), inserter (vi1, vi1.begin()));
    for (auto &item : vi1)
      {
        cout << item << " ";
      }
    cout << endl;

    copy (vi.begin(), vi.end(), front_inserter (vi2));
    for (auto &item : vi2)
      {
        cout << item << " ";
      }
    cout << endl;

    copy (vi.begin(), vi.end(), back_inserter (vi3));
    for (auto &item : vi3)
      {
        cout << item << " ";
      }
    cout << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
