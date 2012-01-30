#include <iostream>
using namespace std;
int main()
{
  char i = 0xff;
  cout << (int)i << endl; //gives you -1, all bits on

  signed char j = 0x7f;
  cout << (int)j << endl; //gives you 127, only signed bit off
  cout << (int)(j+2) << endl; //gives you 128. (they do integer add!)

  for (char k = 0; ; ++k){
    cout << (int) k << endl;
  }


}
