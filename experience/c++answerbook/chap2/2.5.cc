#include <iostream>
#include <limits>

#include <iomanip>
using namespace std;

int main()
{
  for ( char i = 'a'; i <= 'z'; ++i)
    cout << i << ":" <<  setbase(16) << int(i) <<" " ;

  cout << endl;
 
  for ( char i = '0'; i <= '9'; ++i)
    cout << i << ":" << int(i) << " "; 

  cout << endl;

  //assign char to a number
  for ( char i = 0; i <127; ++i)
    cout << i << ":" << int(i) << " ";
}
