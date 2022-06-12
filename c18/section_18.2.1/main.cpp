#include <bits/stdc++.h>

using namespace std;

namespace mathLib::MatrixLib
      {
        class matrix
           {
           public:
              explicit matrix (size_t x) :
                  x(x)
                {

                };

              std::size_t x;

              friend ostream &operator<< (ostream &os, const matrix &matrix)
                {
                  os << "x: " << matrix.x;
                  return os;
                }
           };

        matrix operator* (const matrix &lhs, const matrix &rhs)
          {
            auto m = new matrix { 0 };

            m->x = lhs.x + rhs.x;
            return *m;
          }
      }

int main ()
  {
    mathLib::MatrixLib::matrix matrix1 { 1 };
    mathLib::MatrixLib::matrix matrix2 { 2 };

    auto res = mathLib::MatrixLib::operator*(matrix1, matrix2);

    cout << res << endl;

    return 0;
  }
