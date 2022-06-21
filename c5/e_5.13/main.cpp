#include <iostream>

char next_text();

unsigned int get_bufCnt();

int main()
{

  //    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
  //    char ch = next_text();
  //    switch (ch)
  //    {
  //        case 'a':
  //            aCnt++;
  //            break;
  //        case 'e':
  //            eCnt++;
  //            break;
  //        default:
  //            iouCnt++;
  //            break;
  //    }

  unsigned const ival = 512, jval = 1024, kval = 4096;

  unsigned buffer_size = 0;
  unsigned swt = get_bufCnt();
  switch (swt)
    {
    case ival:
      buffer_size = ival * sizeof (int);
      break;
    case jval:
      buffer_size = jval * sizeof (int);
      break;
    case kval:
      buffer_size = kval * sizeof (int);
      break;
    default:
      break;
    }

  std::cout << buffer_size << std::endl;

  return 0;
}