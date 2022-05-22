#include <bits/stdc++.h>

using namespace std;

void add_family (const string &family, map<string, vector<string>> &family_map)
  {
    family_map[family];
  }

void add_child (const string &family, const string &child, map<string, vector<string>> &family_map)
  {
    family_map[family].push_back(child);
  }

void add_children (const string &family, const vector<string> &children, map<string, vector<string>> &family_map)
  {
    for (const auto &child : children)
      {
        family_map[family].push_back(child);
      }
  }

bool is_punctuation (char c)
  {
    return c == '.' || c == ',';
  }

int main ()
try
  {
    map<string, vector<string>> family_map;

    add_family("Johnson", family_map);
    add_child("Johnson", "Peter", family_map);
    add_child("Johnson", "Anna", family_map);
    add_child("Johnson", "Paul", family_map);

    add_family("Jetson", family_map);
    add_children("Jetson", { "Spacy", "Mars", "Moon", "Pluto" }, family_map);

    for (auto &family : family_map)
      {
        cout << "The " << family.first << ": ";
        for (auto &child : family.second)
          {
            cout << child << " ";
          }
        cout << endl;
      }

    istringstream iss {
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed id nibh velit. Fusce varius urna tortor, eu blandit dolor ornare ut. Mauris vel aliquam nunc. Vestibulum semper cursus semper. Donec volutpat diam ut metus accumsan auctor. Aenean vulputate dignissim diam vel ullamcorper. Quisque vel euismod ipsum. Suspendisse et quam pharetra, fringilla velit vel, malesuada erat. Pellentesque dictum facilisis cursus. Curabitur risus dolor, suscipit quis sapien vitae, blandit finibus orci. Morbi feugiat facilisis mi tincidunt tincidunt. Donec fermentum purus quis velit aliquet posuere. Nulla molestie risus a eros tincidunt, quis mattis quam consequat. Donec non nisi sollicitudin est suscipit varius. Nunc dictum justo massa, eu interdum elit mollis vitae. Suspendisse molestie lobortis dapibus." };

    map<string, size_t> word_count;
    vector<string> exclude { "a", "et", "eu", "id", "sit", "ut" };

    for (string word ; iss >> word ;)
      {
        word.erase(remove_if(word.begin(), word.end(), is_punctuation), word.end());

        transform(word.begin(), word.end(), word.begin(), [] (unsigned char c)
          {
              return std::tolower(c);
          });

        if (find(exclude.begin(), exclude.end(), word) == exclude.end())
          {
            ++word_count[word];
          }
      }

    for (const auto &w : word_count)
      {
        cout << w.first << " occurs " << w.second << ( ( w.second > 1 ) ? " times" : " time" ) << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


