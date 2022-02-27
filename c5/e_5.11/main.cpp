#include <iostream>

int main()
{
    std::string line;
    int aCnt{0}, eCnt{0}, iCnt{0}, oCnt{0}, uCnt{0}, otherCnt{0}, spaceCnt{0}, tabCnt{0}, newlineCnt{0};

    while (std::getline(std::cin, line))
    {
        ++newlineCnt;
        for (auto ch : line)
        {
            switch (ch)
            {
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

    return 0;
}
