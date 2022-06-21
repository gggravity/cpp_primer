#include <bits/stdc++.h>
#include <ostream>

// using namespace std;

struct test1
{
  std::string mem1;

  friend std::ostream &operator<< (std::ostream &os, const test1 &t)
  {
    os << t.mem1;
    return os;
  }
};

struct test2
{
  int mem1;

  friend std::ostream &operator<< (std::ostream &os, const test2 &t)
  {
    os << t.mem1;
    return os;
  }
};

template <typename T> void swap (T &v1, T &v2)
{
  using std::swap;
  swap (v1.mem1, v2.mem1);
}

int main()
{
  test1 t1_1 {"Some string"};
  test1 t1_2 {"another string"};
  test2 t2_1 {123};
  test2 t2_2 {312};

  std::cout << t1_1 << " " << t1_2 << std::endl;
  std::cout << t2_1 << " " << t2_2 << std::endl;

  swap (t1_1, t1_2);
  swap (t2_1, t2_2);

  std::cout << t1_1 << " " << t1_2 << std::endl;
  std::cout << t2_1 << " " << t2_2 << std::endl;

  return 0;
}
