#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main()
{
  string input_1, input_2;
  input_1 = input_2 = "";
  cout << "max digit length is: " << input_1.max_size() << endl;

  cout << "Please enter an integer value" << endl;
  cin >> input_1;
  cout << "Please enter an integer value" << endl;
  cin >> input_2;

  cout << endl;

  vector<int> v1;
  vector<int> v2;

  vector<bitset<4>> vb1;
  vector<bitset<4>> vb2;
  
  for (auto s: input_1) {
    string ss(1, s);
    v1.push_back(stoi(ss));
    vb1.push_back(bitset<4>(stoi(ss)));
  }

  cout << input_1 << " in BCD: ";
  for (auto elem: vb1) {
    cout <<  elem;
    cout << " ";
  }

  cout << endl;

  for (auto s: input_2) {
    string ss(1, s);
    v2.push_back(stoi(ss));
    vb2.push_back(bitset<4>(stoi(ss)));
  }

  cout << input_2 << " in BCD: ";
  for (auto elem: vb2) {
    cout <<  elem;
    cout << " ";
  }
  
  reverse(v1.begin(), v1.end());
  reverse(v2.begin(), v2.end());

  vector<int>::iterator it1 = v1.begin();
  vector<int>::iterator it2 = v2.begin();

  
  vector<int> sum;
  while (true) {
    int first = 0;
    int second = 0;
    if (it1 != v1.end()) {
      first = *it1;
      ++it1;
    }
    if (it2 != v2.end()) {
      second = *it2;
      ++it2;
    }

    sum.push_back(first+second);
    if (it1 == v1.end() && it2 == v2.end()){
      break;
    }
  }

  vector<int> new_sum;
  bool carry = false;
  for (auto i: sum){
    if (carry) {
      i = i + 1;
    }
    if (i > 9){
      i = i - 10;
      carry = true;
    } else {
      carry = false;
    }
    new_sum.push_back(i);
  }
  if (carry){
    new_sum.push_back(1);
  }
	      
  reverse(new_sum.begin(), new_sum.end());

  cout << endl;

  cout << endl;

  for (auto i: new_sum){
    cout << i;
  }
  cout << ":" ;
  for (auto s: new_sum) {
    cout << bitset<4>(s);
    cout <<  "(" << s << ")";
  }
  
  cout << endl;

  cout << "sum in BCD: " ;
  for (auto s: new_sum) {
    cout << bitset<4>(s);
    cout << " ";
  }

  cout << endl;
}

