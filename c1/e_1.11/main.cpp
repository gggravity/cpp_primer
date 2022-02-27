#include <iostream>

void calc_numbers(int, int);

int main() {
    int num1 = 0, num2 = 0;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> num1 >> num2;
    std::cout << "The range between " << num1 << " and " << num2 << " are ";
    calc_numbers(num1, num2);
    std::cout << std::endl;
    return 0;
}

void calc_numbers(int num1, int num2) {
    if (num2 < num1)
    {
        int temp = num2;
        num2 = num1;
        num1 = temp;
    }

    while (num1 <= num2) {
        std::cout << num1 << " ";
        ++num1;
    }
}