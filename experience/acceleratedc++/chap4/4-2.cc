//4-2, 4-3

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

using std::setw;

int getWidth(int i)
{
  int width = 0;
  while ( i / 10 > 0){
    i = i / 10;
    ++width;
  }
  return width+1;
}

int main()
{
  //cout << setw(10);
  //cout << 77 << endl;

  int last = 99;
  for (int i = 1; i < last ; ++i){
    cout << setw(getWidth(last)) << i << " " 
	 << setw(getWidth(last*last)) << i * i << endl;
  }
  return 0;
}
