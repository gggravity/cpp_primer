#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> i_vector;
    std::vector<std::string> s_vector = i_vector;
    std::vector<std::string> s_vector(10, "null");

    return 0;
}
