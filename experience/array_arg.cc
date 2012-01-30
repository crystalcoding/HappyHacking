#include <iostream>
using namespace std;

void f(int (&c)[20]) //(int (&)[20])  is nameless
{
  cout << c[20] << endl;
}
int main()
{
  int a[20];
  a[20] = 10;
  f(a);
}
