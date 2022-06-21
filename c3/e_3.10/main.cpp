#include <iostream>

int main()
{
  std::string string {"fsdfsff,fsdfsdfsd,..,,.dsfsdfsd,..fsdfs.fsdfsdfs,f f fsdf sdf,s"};
  std::string new_string;

  for (char c : string)
    {
      if (! std::ispunct (c))
        {
          new_string += c;
        }
    }

  std::cout << new_string;

  return 0;
}
