#include <iostream>
#include <vector>
#include <iterator>
#include <bitset>
using namespace std;

vector<int> dec_to_binary(int dec)
{
  vector<int> v;
  while (dec != 0){
    //insert is not good here, forcing all elements
    //  to move after begin
    //v.insert(v.begin(),dec%2);
    //usr push_back is better
    v.push_back(dec%2);
    cout << dec/2 << "," << dec%2 << endl;
    dec = dec/2 ; //integer division, e.g 77/2 = 38
  }
 
  copy(v.begin(),v.end(),ostream_iterator<int>(cout,""));
  cout << endl;
  //reverse the order, easy to read as big-endian
  //v.assign(v.rbegin(), v.rend()); //bug!, assgin and iterator to itself
  vector<int> v2(v.rbegin(), v.rend());
  cout << endl;
  return v2;
}

void use_bitset(int dec)
{
  // 8 bits in each byte
   bitset<8*sizeof(int)> bs(dec);
   cout << bs << endl;
}

int main()
{
  vector<int> v = dec_to_binary(1234);
  copy(v.begin(),v.end(),ostream_iterator<int>(cout,""));
  cout << endl;

  cout << "binary:";
  use_bitset(1234);

  cout << "hex:"<< hex << 1234;
}
