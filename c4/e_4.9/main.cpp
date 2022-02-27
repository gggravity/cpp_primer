#include <iostream>

int main()
{
    const char *cp = "Hello World";
    if (cp && *cp)
    {
        std::cout << "true" << std::endl;
    } else
    {
        std::cout << "false" << std::endl;
    }
    return 0;
}
