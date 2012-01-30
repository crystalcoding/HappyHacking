#include <iostream>
using namespace std;

void printInfo(char myChar, char* myP) 
{
  cout << "myChar = " << myChar << endl;
  cout << "&myP = " << &myP << endl;
  cout << "*myp = " << *myP << endl;
  cout << "----" << endl;
}

void printArray(char array[], int length)
{
  for(int i = 0; i < length; ++i)
    {
      cout << array[i] << endl;
    }
}

int main()
{
  char a = 'a';
  char* ap;
  ap = &a;
 
  cout << "before a = *app++" << endl;
  printInfo(a, ap);
  a = *ap++;
  cout << "after a = *ap++" << endl;
  //printInfo(a, &ap); wrong ??
  printInfo(a, ap);

   
  char array[4];
  array[0] = 'a';
  array[1] = 'b';
  array[2] = 'c';
  array[3] = '\0';
  
  printArray(array, 4);

  char* arrayP  = &array[0];

  array[0]  = *arrayP++;
  printArray(array, 4);

  cout << "*arrayP = " << *arrayP << endl;
  //array[0] = ++*arrayP;
  //printInfo(array[0], arrayP);

  
}


