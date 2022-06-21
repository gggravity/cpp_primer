#include <iostream>

int main()
{
  char ch;
  int aCnt {0}, eCnt {0}, iCnt {0}, oCnt {0}, uCnt {0};

  while (std::cin >> ch)
    {
      if (ch == 'a')
        {
          ++aCnt;
        }
      if (ch == 'e')
        {
          ++eCnt;
        }
      if (ch == 'i')
        {
          ++iCnt;
        }
      if (ch == 'o')
        {
          ++oCnt;
        }
      if (ch == 'u')
        {
          ++uCnt;
        }
    }
  std::cout << "The vowel counts are:" << std::endl;
  std::cout << "a: " << aCnt << std::endl;
  std::cout << "e: " << eCnt << std::endl;
  std::cout << "i: " << iCnt << std::endl;
  std::cout << "o: " << oCnt << std::endl;
  std::cout << "u: " << uCnt << std::endl;

  return 0;
}
