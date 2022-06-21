#include <bits/stdc++.h>

using namespace std;

bool is_punctuation (char c) { return c == '.' || c == ','; }

int main()
try
  {
    istringstream iss {
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed id nibh velit. Fusce varius urna tortor, eu blandit dolor ornare ut. Mauris vel aliquam nunc. Vestibulum semper cursus semper. Donec volutpat diam ut metus accumsan auctor. Aenean vulputate dignissim diam vel ullamcorper. Quisque vel euismod ipsum. Suspendisse et quam pharetra, fringilla velit vel, malesuada erat. Pellentesque dictum facilisis cursus. Curabitur risus dolor, suscipit quis sapien vitae, blandit finibus orci. Morbi feugiat facilisis mi tincidunt tincidunt. Donec fermentum purus quis velit aliquet posuere. Nulla molestie risus a eros tincidunt, quis mattis quam consequat. Donec non nisi sollicitudin est suscipit varius. Nunc dictum justo massa, eu interdum elit mollis vitae. Suspendisse molestie lobortis dapibus."};

    map<string, size_t> word_count;
    set<string> exclude {"a", "et", "eu", "id", "sit", "ut"};

    for (string word; iss >> word;)
      {
        word.erase (remove_if (word.begin(), word.end(), is_punctuation), word.end());

        transform (word.begin(), word.end(), word.begin(), [] (unsigned char c) { return std::tolower (c); });

        if (exclude.find (word) == exclude.end())
          {
            ++word_count[word];
          }
      }

    for (const auto &w : word_count)
      {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
      }

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
