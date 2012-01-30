#include <iostream>

#include "Str.h"

using std::cout; using std::endl;
int main()
{
  Str s = "abc"; //this will call the copy constructor
  Str y = "def"; //this will call the copy constructor
  Str z = y;
  cout << s+y << endl;
  cout << z << endl;
  return 0;
}
