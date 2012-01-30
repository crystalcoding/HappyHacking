#include <iostream>

using namespace std;

int main()
{
  char str[] = "a short string";
  cout << sizeof(str) << endl;

  /*
  int i = 0;
  for(; str[i] != '\0'; ++i);

  cout << "length of str is " << i << endl;
  */

  cout << "length of str is " << strlen(str) << endl;
}
