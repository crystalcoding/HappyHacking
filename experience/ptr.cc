#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  const char digits[] = { "0123456789abcdefghijklmnopqrstuvwxyz" };
  const char *sc = digits;
  const char first = '0';
  const char second = '1';
  
  const char check = *sc == '0' ? *sc++ : 'x';
  cout << "check:" << check << endl; // 0
  cout << "*sc:" << *sc << endl; // 1
  cout << endl;

  if ( *sc++ == first) // false  //*sc now is 2
    cout << "*sc++ == first" << endl;
  if ( *sc == second) // false 
    cout << "*sc == second" << endl;

  cout << "*sc:" << *sc << endl; //2

  cout << "-------------------------" <<endl;

  int count = 0;
  int p = 10;
  while(--p)
    cout << p << " (count:" << ++count << ") ";
  cout << endl;

  int j = 10;
  count = 0;
  while(j--)    //9876543210
    cout << j << " (count:" << ++count << ") "; //    cout << j << " (count:" << count++ << ") ";
  cout << endl;

  cout << "------------------------"<< endl;
  const char i[] = { "987654321x"};
  count = 0;
  const char *ipt = i;
  while(*ipt++)
    cout << *ipt << " (count:" << ++count << "} ";

  cout << endl;

  count = 0;
  ipt = i;
  while(*++ipt)
    cout << *ipt << " (count:" << ++count << ") ";
 
  /* wrong error: increment of read-only locatio
  cout << endl;
  count = 0;
  ipt = i;
  while(++*ipt)  error: increment of read-only location
    cout << *ipt << " (count:" << ++count << ") ";
  */ 

  cout << endl <<"--------------" << endl;
  
  char ichr[] = {"abc"};
  char *ichrp = ichr;
  //*ichrp++;
  printf("%c\n", *ichrp++); //a
  //cout << *ichrp++ << endl; //a
  cout << *ichrp << endl; //b


  char jchr[] = {"abc"};
  char *jchrp = jchr;
  //*++jchrp;
  //printf("%c\n", *++jchrp); //b
  cout << *++jchrp << endl; //b
  
  cout << "-------------" << endl;

  int index = 0;
  cout << jchr[++index] << endl;  //b 
  index = 0;
  cout << jchr[index++] << endl;  //a
  cout << index << endl << "------------" << endl; //print 1

  cout << endl;
  char upc[] = { "ab"};
  char *upcp = upc;

  ///independent lines
  //cout << ++*upcp << endl; //b
  //cout << *upcp++ <<endl; //a
  //cout << *(upcp++) <<endl; //a
  //cout << *++upcp << endl; //b
  //cout << ++(*upcp) << endl; //b
  //cout << *upcp << endl; //a
  //cout << upcp << endl; //ab
  //cout << &upcp << endl; //0x22fedc print address
  //end of independent lines
}
