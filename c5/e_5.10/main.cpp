#include <iostream>

int main ()
{
  char ch;
  int aCnt{0}, eCnt{0}, iCnt{0}, oCnt{0}, uCnt{0}, otherCnt{0};

  while (std::cin >> ch)
    {
      switch (ch)
        {
      case 'a':
      case 'A':++aCnt;
          break;
      case 'e':
      case 'E':++eCnt;
          break;
      case 'i':
      case 'I':++iCnt;
          break;
      case 'o':
      case 'O':++oCnt;
          break;
      case 'u':
      case 'U':++uCnt;
          break;
      default:++otherCnt;
          break;
        }

    }
  std::cout << "The vowel counts are:" << std::endl;
  std::cout << "aA: " << aCnt << std::endl;
  std::cout << "eE: " << eCnt << std::endl;
  std::cout << "iI: " << iCnt << std::endl;
  std::cout << "oO: " << oCnt << std::endl;
  std::cout << "uU: " << uCnt << std::endl;
  std::cout << "other: " << otherCnt << std::endl;

  return 0;
}
