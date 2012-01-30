#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}
int main()
{
  int i=3; int j=4;
  swap(&i, &j);
  cout << "i, j= " << i <<", " << j << endl;

  swap(i, j);
  cout << "i, j= " << i <<", " << j << endl;
}
