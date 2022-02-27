#include <iostream>
#include <string>

int main()
{
    std::string final_grade;
    int grade = 44;

    final_grade = (grade > 90) ? "high pass"
                  : (grade < 60) ? "fail"
                  : (grade < 75) ? "low pass" : "pass";

    if (grade > 90)
        std::cout << "Final grade is: high pass" << std::endl;
    else if (grade > 75)
        std::cout << "Final grade is: pass" << std::endl;
    else if (grade > 60)
        std::cout << "Final grade is: low pass" << std::endl;
    else
        std::cout << "Final grade is: fail" << std::endl;


    std::cout << "Final grade is: " << final_grade << std::endl;
    return 0;
}
