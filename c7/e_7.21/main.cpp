#include "Sales_data.h"
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
  Sales_data sales_data ("0-201-78655", 5, 98.50);
  print (cout, sales_data);

  return 0;
}