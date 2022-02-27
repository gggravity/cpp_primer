#include <iostream>

using namespace std;

int main ()
{
  //    how now now now brown brown brown brown brown brown cow cow .
  string last_word, word, max_word;
  int counter{0}, max_count{0};

  while (cin >> word && word != ".")
    {
      if (word == ".")
        continue;
      if (last_word != word)
        {
          last_word = word;
          counter = 0;
        }
      if (word == last_word)
        {
          ++counter;
        }
      if (counter >= max_count)
        {
          max_count = counter;
          max_word = word;
        }
    }

  cout << "max_word: " << max_word << endl;
  cout << "max_count: " << max_count << endl;

  return 0;
}
