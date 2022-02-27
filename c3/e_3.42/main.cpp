#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int arr[vec.size()];
    int i = 0;

    for (auto v : vec)
    {
        arr[i] = v;
        i++;
    }

    for (auto a : arr)
    {
        cout << a << " ";
    }

    return 0;
}
