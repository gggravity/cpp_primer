#include <iostream>
#include <vector>

int main()
{
    std::vector<int> grades = {42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
    std::vector<int> buckets(11, 0);

    for (auto grade : grades)
    {
        std::cout << grade << " ";
    }

    std::cout << std::endl;

    for (auto grade = grades.begin(); grade != grades.end(); ++grade)
    {
        buckets[*grade / 10]++;
    }

    for (auto bucket : buckets)
    {
        std::cout << bucket << " ";
    }

    return 0;
}
