#include <iostream>
using namespace std;

void swappt(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void swapref(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}
int main()
{
  int i=1;
  int j=2;
  
  swappt(&i,&j);
  cout << "i, j = " << i << ","<< j<< endl;

  swapref(i,j);
  cout << "i, j = " << i << "," <<j <<endl;

  return 0;
}
