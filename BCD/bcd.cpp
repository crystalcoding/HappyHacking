#include <iostream>
#include <string>
#include <bitset>
#include <limits>

using namespace std;

string to_binary_string(int money)
{
  string ret = "";
  while (money != 0) {
    if ( (money%2) == 0) {
      //this bit is 0
      ret = "0" + ret;
    } else {
      //this bit is 1
      ret = "1" + ret;
    }
    money /= 2;
  }
  return ret;
}

int main()
{
  cout.precision(8); // deliberately break float precision
  float money = 11111111;
  float triple_money = money + money + money;
  cout << triple_money << endl; // = 33333332 angry customer 

  const string money_str = to_binary_string(money);
  bitset<32> bitvec(to_binary_string(money));

  cout << bitvec << endl;
  
  bitset<32> b2(11);
  //cout << b2 << endl;
  string input;
  cout << "Please enter an integer value" << endl;
  cin >> input;
  for (auto s: input) {
    string ss(1, s);
    //cout << "s is: " << s << "  ";
    bitset<4> bits(stoi(ss));
    //cout << bits.to_ulong() << " ";
    cout << bits.to_string() << " ";
    
  }

  cout << endl;
}

