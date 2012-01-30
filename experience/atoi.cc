#include <iostream>
#include <cstring>
using namespace std;

int atoi(const char* c)
{

  /*
  //null character '\0', value is '0'
  while( *c != 0){ //"*c++ does not work!
    cout << *c;
    ++c;
  }
  */
}
void take_char(const char c)
{
  cout << "take_char" << endl;
}
int main()
{
  char c[] = "53112412342";
  //int result = atoi(c);
  //cout << result;

  char i = '9';
  int iascii = i - '0';
 
  char array[] = "abcdefg";
  //cout << sizeof(array) << endl; //print4
  //cout << strlen(array) << endl; //print3
  //take_char(iascii); //??? why this will work?

  char *ap = &array[0];
  cout << *ap << endl; //print a
  cout << *ap++ << endl; //why = *(ap++) !? print a //increment later
  cout << *ap << endl; //print b
  cout << *++ap << endl; //print c //increment first
  cout << *ap << endl; //print c
  cout << ++*ap << endl; //print d  = ++(*ap)
  cout << *ap << endl; //print d

  int a = 3;
  while(a--){ //first run, a=2 already
    cout << "a=" << a << " ";
  }
  return 0;
}






















