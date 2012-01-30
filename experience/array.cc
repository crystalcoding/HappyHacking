#include <iostream>
#include <vector>
using namespace std;

void print()
{
  cout << "test" << end;
}

int main()
{
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  for(int i = 0; i < 10; ++i)
    {
      cout << *(array+i) << endl;
    }
   
   

  
}
