#include <bits/stdc++.h>

using namespace std;

template <size_t Answers> struct Quiz
{
  Quiz (const string &name, const string &results_string) : name (name)
  {
    auto reversed {results_string};
    reverse (reversed.begin(), reversed.end());
    results = bitset<Answers> (string (reversed));
  }

  string name;
  bitset<Answers> results;
};

template <typename Quiz> auto print_result (Quiz quiz)
{
  for (size_t i {0}; i < quiz.results.size(); ++i)
    {
      if (quiz.results.test (i))
        {
          cout << quiz.name << " answered question " << i + 1 << " with a yes" << endl;
        }
      else
        {
          cout << quiz.name << " answered question " << i + 1 << " with a no" << endl;
        }
    }
}

template <typename Quiz> auto set_score (Quiz &quiz, size_t position, bool result)
{
  --position;
  quiz.results.set (position, result);
}

template <typename Quiz> auto get_results (Quiz quiz, Quiz answers)
{
  auto results {quiz.results ^ answers.results};
  results.flip();
  auto score {to_string (results.count()) + " / " + to_string (quiz.results.size())};
  return score;
}

int main()
try
  {
    Quiz<10> anna {"Anna", "1001100011"};
    print_result (anna);
    //    set_score(anna, 1, false);
    cout << "-------------------" << endl;
    //    print_result(anna);

    Quiz<10> results {"The Correct Answers", "1110001110"};

    cout << get_results (anna, results) << endl;

    return 0;
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
