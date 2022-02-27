#include <iostream>
#include <vector>

int main()
{
    std::string string;
    std::vector<std::string> vector;

    while (std::getline(std::cin, string))
    {
        if (string.empty())
            break;
        vector.push_back(string);
    }
    std::cout << "The letters in the vector are: " << std::endl;

    for (std::string &s : vector)
    {
        std::cout << s << " ";
    }


    return 0;
}
