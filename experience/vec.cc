#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v(3);
  v[1] = 5;
  cout << v[0] << endl;
  cout << v[1] << endl;

  v[2].operator()(2);
  cout << v[2] << endl;
}
