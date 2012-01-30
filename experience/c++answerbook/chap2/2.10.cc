#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  const int one = 1;
  //one = 2;

  const int num[] = {1, 2};
  //num[1] = 2;

  //int i = const_cast<int>(num);??? doesn't work
}
