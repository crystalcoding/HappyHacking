#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;


int main()
{
  cout << "input a set sequence, e.g. 123 is {1,2,3}:" << endl;
  cout << "(only handle single digit set so far...)" << endl;
  string original_set;
  cin >> original_set;

  const int size = original_set.length();

  //power of 2 
  int max_rank = (1 << size );
  cout<< "max_rank:"<<max_rank << endl;

  vector<string> result;
  for (int i=1; i<max_rank; ++i){
    //size of 8 tests 3 elements
    bitset<8> b(i);

    result.push_back("");
    string s;
    for(int j=0;j< static_cast<int>(original_set.length());++j){
      if (b.test(j)) {

        result.back() += original_set[j];
	s += original_set[j];
      }
    }
    cout << "result.back():"<<result.back()<<endl;
    cout << "s:"<<s << endl;
  }
}
