#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> Child;

void add_family (const string &family, map<string, vector<Child>> &family_map) { family_map[family]; }

void add_child (const string &family, const Child &child, map<string, vector<Child>> &family_map)
{
  family_map[family].push_back (child);
}

void add_children (const string &family, const vector<Child> &children, map<string, vector<Child>> &family_map)
{
  for (const auto &child : children)
    {
      family_map[family].push_back (child);
    }
}

int main()
try
  {
    // e 11.12
    /*
    vector<pair<string, int>> vp;

    for (int i { 0 } ; i < 10 ; ++i)
      {
        vp.emplace_back("element" + to_string(i), i);
      }

    for (auto &p : vp)
      {
        cout << p.first << " -> " << p.second << endl;
      }
*/
    // e 11.14

    map<string, vector<pair<string, int>>> family_map;

    add_family ("Johnson", family_map);
    add_child ("Johnson", {"Peter", 13}, family_map);
    add_child ("Johnson", {"Anna", 19}, family_map);
    add_child ("Johnson", {"Paul", 2}, family_map);

    add_family ("Jetson", family_map);
    add_children ("Jetson", {{"Spacy", 10}, {"Mars", 12}, {"Moon", 9}, {"Pluto", 2}}, family_map);

    for (auto &family : family_map)
      {
        cout << "The " << family.first << ": ";
        for (auto &child : family.second)
          {
            cout << child.first << " " << child.second;
            cout << (child != family.second.back() ? ", " : ".");
          }
        cout << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
