//
// Created by martin on 29/09/2021.
//

int factorial (int number)
{
  int result {1};

  while (number > 1)
    {
      result *= number--;
    }

  return result;
}