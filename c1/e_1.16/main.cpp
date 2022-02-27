#include <iostream>

int main() {
    int value{0}, sum{0};

    std::cout << "Enter a set of numbers (enter a non integer to exit): " << std::endl;
    while (std::cin >> value) {
        sum += value;
        std::cout << "The sum is: " << sum << std::endl;
    }

    return 0;
}
