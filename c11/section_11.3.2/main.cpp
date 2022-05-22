#include <bits/stdc++.h>

using namespace std;

typedef multimap<string, string> Family_map;

bool is_punctuation (char c)
  {
    return c == '.' || c == ',';
  }

void add_child (const string &family, const string &child, Family_map &family_map)
  {
    family_map.insert({ family, child });
  }

void add_children (const string &family, const vector<string> &children, Family_map &family_map)
  {
    for (const auto &child : children)
      {
        family_map.insert({ family, child });
      }
  }

int main ()
try
  {
//    istringstream iss {
//        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed id nibh velit. Fusce varius urna tortor, eu blandit dolor ornare ut. Mauris vel aliquam nunc. Vestibulum semper cursus semper. Donec volutpat diam ut metus accumsan auctor. Aenean vulputate dignissim diam vel ullamcorper. Quisque vel euismod ipsum. Suspendisse et quam pharetra, fringilla velit vel, malesuada erat. Pellentesque dictum facilisis cursus. Curabitur risus dolor, suscipit quis sapien vitae, blandit finibus orci. Morbi feugiat facilisis mi tincidunt tincidunt. Donec fermentum purus quis velit aliquet posuere. Nulla molestie risus a eros tincidunt, quis mattis quam consequat. Donec non nisi sollicitudin est suscipit varius. Nunc dictum justo massa, eu interdum elit mollis vitae. Suspendisse molestie lobortis dapibus." };
//
//    map<string, size_t> word_count;
//    set<string> exclude { "a", "et", "eu", "id", "sit", "ut" };
//
//    for (string word ; iss >> word ;)
//      {
//        word.erase(remove_if(word.begin(), word.end(), is_punctuation), word.end());
//
//        transform(word.begin(), word.end(), word.begin(), [] (unsigned char c)
//          {
//              return std::tolower(c);
//          });
//
//        if (exclude.find(word) == exclude.end())
//          {
////            ++word_count[word];
//            auto ret = word_count.insert({ word, 1 });
//            if (!ret.second)
//              {
//                ++ret.first->second;
//              }
//          }
//      }
//
//    for (const auto &w : word_count)
//      {
//        if (w.second > 1)
//          {
//            cout << w.first << " occurs " << w.second << ( ( w.second > 1 ) ? " times" : " time" ) << endl;
//          }
//      }

    // e 11.21

//    istringstream iss {
//        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed id nibh velit. Fusce varius urna tortor, eu blandit dolor ornare ut. Mauris vel aliquam nunc. Vestibulum semper cursus semper. Donec volutpat diam ut metus accumsan auctor. Aenean vulputate dignissim diam vel ullamcorper. Quisque vel euismod ipsum. Suspendisse et quam pharetra, fringilla velit vel, malesuada erat. Pellentesque dictum facilisis cursus. Curabitur risus dolor, suscipit quis sapien vitae, blandit finibus orci. Morbi feugiat facilisis mi tincidunt tincidunt. Donec fermentum purus quis velit aliquet posuere. Nulla molestie risus a eros tincidunt, quis mattis quam consequat. Donec non nisi sollicitudin est suscipit varius. Nunc dictum justo massa, eu interdum elit mollis vitae. Suspendisse molestie lobortis dapibus." };
//
//    map<string, size_t> word_count;
//
//    string word;
//
//    while (iss >> word)
//      {
//        ++word_count.insert({ word, 0 }).first->second; // complicated way of writing ++word_count[word]
//      }
//
//    for (const auto &w : word_count)
//      {
//        cout << w.first << " occurs " << w.second << ( ( w.second > 1 ) ? " times" : " time" ) << endl;
//      }

    // e 11.22

//    map<string, vector<int>> m;
//    auto ret1 = m.insert({ "1", { 1, 2 } });
//    pair<map<string, vector<int>>::iterator, bool> ret2 = m.insert({ "1", { 1, 2 } });
//    // see auto or pair<map<string, vector<int>>::iterator, bool>

    // e 11.23


    Family_map family_map;

    add_child("Johnson", "Peter", family_map);
    add_child("Johnson", "Anna", family_map);
    add_child("Johnson", "Paul", family_map);

    add_children("Jetson", { "Spacy", "Mars", "Moon", "Pluto" }, family_map);

    for (auto &entry : family_map)
      {
        cout << entry.first << " -> " << entry.second << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


