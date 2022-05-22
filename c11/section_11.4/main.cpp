#include <bits/stdc++.h>

bool is_punctuation (char c)
  {
    return c == '.' || c == ',';
  }

using namespace std;

unordered_map<string, string> buildMap (ifstream &map_file)
  {
    unordered_map<string, string> trans_map;
    string key;
    string value;

    while (map_file >> key && getline(map_file, value))
      {
        if (value.size() > 1)
          {
            trans_map[key] = value.substr(1);
//            trans_map.insert({key, value.substr(1)});
          }
        else
          {
            throw runtime_error("no rules for " + key);
          }
      }
    return trans_map;
  }

const string &transform (const string &s, const unordered_map<string, string> &m)
  {
    auto map_it = m.find(s);


    if (map_it != m.cend())
      {
        return map_it->second;
      }
    else
      {
        return s;
      }
  }

void word_transform (ifstream &map_file, ifstream &input)
  {
    auto trans_map = buildMap(map_file);

    string text;

    while (getline(input, text))
      {
        istringstream stream { text };
        string word;
        bool first_word { true };
        while (stream >> word)
          {
            if (first_word)
              {
                first_word = false;
              }
            else
              {
                cout << " ";
              }
            cout << transform(word, trans_map);
          }
        cout << endl;
      }
  }

int main ()
try
  {
//    istringstream iss {
//        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed id nibh velit. Fusce varius urna tortor, eu blandit dolor ornare ut. Mauris vel aliquam nunc. Vestibulum semper cursus semper. Donec volutpat diam ut metus accumsan auctor. Aenean vulputate dignissim diam vel ullamcorper. Quisque vel euismod ipsum. Suspendisse et quam pharetra, fringilla velit vel, malesuada erat. Pellentesque dictum facilisis cursus. Curabitur risus dolor, suscipit quis sapien vitae, blandit finibus orci. Morbi feugiat facilisis mi tincidunt tincidunt. Donec fermentum purus quis velit aliquet posuere. Nulla molestie risus a eros tincidunt, quis mattis quam consequat. Donec non nisi sollicitudin est suscipit varius. Nunc dictum justo massa, eu interdum elit mollis vitae. Suspendisse molestie lobortis dapibus." };
//
//    unordered_map<string, size_t> word_count;
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
//            ++word_count[word];
//          }
//      }
//
//    for (const auto &w : word_count)
//      {
//        cout << w.first << " occurs " << w.second << ( ( w.second > 1 ) ? " times" : " time" ) << endl;
//      }



//
    ifstream map_file { "../map_file.txt" };
    ifstream input { "../input.txt" };

    word_transform(map_file,input);


    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


