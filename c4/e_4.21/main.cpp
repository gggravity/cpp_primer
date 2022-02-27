#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto &v : vec)
    {
        v = v % 2 ? v : v*2;
        cout << v << " ";
    }


    return 0;
}
