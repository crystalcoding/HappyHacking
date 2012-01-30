#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
  int array[3] = {0, 1, 2};
  int count = 0;
  int result = 5;
  array[count++] = result;
  cout << array[0] << array[1] << array[2] << endl;
  cout << count << endl;
}
