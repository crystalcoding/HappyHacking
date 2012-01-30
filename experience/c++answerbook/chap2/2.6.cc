#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
  union bit_pattern
  {
    short ptr;
    char byte[sizeof(short)];
  } bt;

  bt.ptr = 0x0201;
  for (int i = 0; i < sizeof(short); ++i)
    {
      cout << "printable character:" << endl;
      cout << "i=" << i << "," << setbase(16)<< bt.byte[i] << endl;

      if (bt.byte[i] == 2)
	cout << "byte " << i << " is 2" << endl;

      if (bt.byte[i] == 1)
	cout << "byte " << i << " is 1" << endl;

    }

  cout << "sizeof(short):" << sizeof(short) << endl;
  cout << endl;
}
