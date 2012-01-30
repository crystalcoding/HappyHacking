#include <iostream>

using namespace std;

int main()
{
  int *p;
  int *a;
  *p++; //*(p++)
  *--p; //*(--p)
  ++a--; // (++a)-- wrong, it is ++(a--) 
  (int *)p->m; //casting? (int*)(p->m)
  *p.m; // *(p.m)
  *a[i]; // *(a[i])
  
}
