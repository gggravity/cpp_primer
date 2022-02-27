#include <iostream>

int main()
{

    for (int score = 100; score >= 0; score--)
    {
        if (score < 60)
        {
            std::cout << "score: " << score << " grade: F";
        }
        if (score >= 60 && score < 70)
        {
            std::cout << "score: " << score << " grade: D";
        }
        if (score >= 70 && score < 80)
        {
            std::cout << "score: " << score << " grade: C";
        }
        if (score >= 80 && score < 90)
        {
            std::cout << "score: " << score << " grade: B";
        }
        if (score >= 90 && score < 100)
        {
            std::cout << "score: " << score << " grade: A";
        }
        if (score == 100)
        {
            std::cout << "score: " << score << " grade: A++";
        }
        if (score != 100 && score >= 60)
        {
            if (score % 10 > 7)
            {
                std::cout << "+";
            }
            if (score % 10 < 3)
            {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
