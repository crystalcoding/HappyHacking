#include <iostream>

int main()
{
  int *pi = new int(10);
  int *pia = new int[10];

  while (*pi < 11) {
    pia[*pi] = *pi;
    *pi = *pi+1;
  }

  delete pi;
  delete[] pia;
}
