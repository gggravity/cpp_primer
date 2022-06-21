#include <iostream>
// ff fi fl ff ff ff if fl fl fl fl flfl
int main()
{
  std::string line;
  int aCnt {0}, eCnt {0}, iCnt {0}, oCnt {0}, uCnt {0}, otherCnt {0}, spaceCnt {0}, tabCnt {0}, newlineCnt {0};
  int ffCnt {0}, flCnt {0}, fiCnt {0};

  while (std::getline (std::cin, line))
    {
      ++newlineCnt;
      int next_index {0};
      for (auto ch : line)
        {
          next_index++;
          switch (ch)
            {
            case 'f':
              if (line[next_index] == 'f')
                {
                  ++ffCnt;
                }
              if (line[next_index] == 'l')
                {
                  ++flCnt;
                }
              if (line[next_index] == 'i')
                {
                  ++fiCnt;
                }
              break;
            case ' ':
              ++spaceCnt;
              break;
            case '\t':
              ++tabCnt;
              break;
            case 'a':
            case 'A':
              ++aCnt;
              break;
            case 'e':
            case 'E':
              ++eCnt;
              break;
            case 'i':
            case 'I':
              ++iCnt;
              break;
            case 'o':
            case 'O':
              ++oCnt;
              break;
            case 'u':
            case 'U':
              ++uCnt;
              break;
            default:
              ++otherCnt;
              break;
            }
        }
    }
  std::cout << "The vowel counts are:" << std::endl;
  std::cout << "aA: " << aCnt << std::endl;
  std::cout << "eE: " << eCnt << std::endl;
  std::cout << "iI: " << iCnt << std::endl;
  std::cout << "oO: " << oCnt << std::endl;
  std::cout << "uU: " << uCnt << std::endl;
  std::cout << "spaces: " << spaceCnt << std::endl;
  std::cout << "tabs: " << tabCnt << std::endl;
  std::cout << "newlines: " << newlineCnt << std::endl;
  std::cout << "other: " << otherCnt << std::endl;
  std::cout << "ff: " << ffCnt << std::endl;
  std::cout << "fi: " << fiCnt << std::endl;
  std::cout << "fl: " << flCnt << std::endl;

  return 0;
}
