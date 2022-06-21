#include <iostream>

int main()
{

  for (int score = 100; score >= 0; score--)
    {
      (score < 60) ? std::cout << "score: " << score << " grade: F" :

      (score >= 60 && score < 70)    ? std::cout << "score: " << score << " grade: D"
      : (score >= 70 && score < 80)  ? std::cout << "score: " << score << " grade: C"
      : (score >= 80 && score < 90)  ? std::cout << "score: " << score << " grade: B"
      : (score >= 90 && score < 100) ? std::cout << "score: " << score << " grade: A"
      : (score == 100)               ? std::cout << "score: " << score << " grade: A++"
                                     : std::cout << "";

      if (score != 100 && score >= 60)
        {
          (score % 10 > 7) ? std::cout << "+" : (score % 10 < 3) ? std::cout << "-" : std::cout << "";
        }
      std::cout << std::endl;
    }
  return 0;
}
