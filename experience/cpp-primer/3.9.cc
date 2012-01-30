#include <iostream>

using namespace std;

int mystrlen(const char* a)
{
  int i=0;
  while(*a++ != '\0')
    ++i;

  return i;

}
char* cat(const char* a, const char* b)
{
  int size = mystrlen(a) + mystrlen(b) + 1; 
  char* ret = new char[size+1];

  int i, j;
  i = j = 0;
  for(; i<mystrlen(a); ++i, ++j)
    ret[i] = a[i]; //alternative way? pointer?

  //++j; bug 

  for(int k=0; j<size-1; ++j, ++k)
    ret[j] = b[k];

  ret[j+1] = '\0';

  return ret;
}

char* rev(const char* a)
{
  char* ret = new char[mystrlen(a)+1];
  
  for(int i = mystrlen(a), j=0; i>0; --i, ++j)
    ret[j] = a[i-1];

  ret[mystrlen(a)+1] = '\0';

  return ret;
}

int main()
{
  const char* a = "123"; //need const, alternative form?
  const char* b = "456";
  const char* c = cat(a, b);
  cout << mystrlen(a) << endl;
  
  cout << cat(a, b) << endl;
  cout << rev(c) << endl;
}
