#include <iostream>

int main() {
    int v1 = 0;
    int v2 = 0;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1;
    std::cin >> v2;
    std::cout << "The sum of the two numbers is: ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
