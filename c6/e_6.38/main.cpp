#include <iostream>

using namespace std;

int odd[] = {1, 2, 5, 6, 9};
int even[] = {0, 2, 4, 6, 8};

auto arrPrt (int i) -> int (&)[5] { return (i % 2 ? odd : even); }

int main()
{

  for (auto i : arrPrt (9))
    {
      cout << i << " ";
    }

  return 0;
}
