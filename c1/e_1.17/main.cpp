#include <iostream>

int main()
{
    int currVal = 0, val = 0;

    std::cout << "Enter some numbers with a space in between and end with a x:" << std::endl;

    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++cnt;
            } else
            {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }
    std::cout << "The end.";
    return 0;
}
//42 42 42 42 42 55 55 62 100 100 100