#include <iostream>
using namespace std;

int main()
{
  char digits[] = { "0123456789abcdefghijklmnopqrstuvwxyz"};
  char* dptr = digits;
  char _char = 10;
  cout << "dptr - _int:" << dptr - _char << endl;
  cout << "d:" << dptr << endl;
  long x = 0;
  int base = 10;
  char c = 97;
  char *a = &c;
  cout << "c:"<< c << endl;
  x = x * base + (a - digits);
  cout << "x:" << x << endl;

  cout << "digits:" << digits << endl;
  cout << "digits[0]:" << digits[0] << endl;
  cout << "&digits:" << &digits << endl;
  cout << "a:" << a << endl;
  cout << "*a:" << *a << endl;
  cout << "&a:" << &a << endl; 

  char d[] = {"3"};
  char s[] = {"1"};
  cout << "d-s:" << d-s << endl; //always 16
  cout << "&d:" << &d << endl;
  cout << "&s:" << &s << endl;
  cout << "sizeof d:" << sizeof(d) << endl;
  cout << "sizeof s:" << sizeof(s) << endl;
  cout << "sizeof char" << sizeof(char) << endl;
  cout << "sizeof int" << sizeof(int) << endl;
  cout << "sizeof short" << sizeof(short) << endl;
  cout << "sizeof long" << sizeof(long) << endl;
  cout << "sizeof float" << sizeof(float) << endl;
  cout << "sizeof double" << sizeof(double) << endl;
}
