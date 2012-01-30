#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::string;
int main()
{
  cout << " please enter your name: ";
  string name;
  cin >> name;

  const string greeting = "Hello, " + name + "!";

  const int pad = 1;

  const int rows = pad*2 + 3;
  const string::size_type cols = greeting.size() + 2*pad + 2;
  cout << endl;

  for(int r = 0; r != rows; ++r){
    string::size_type c = 0;
    while(c != cols) {
      if (r == pad + 1 && c == pad + 1){
	cout << greeting;
	c += greeting.size();
	}
      else {
	if (r == 0 || r == rows - 1 || c == 0 || c == cols -1){
	  cout << "*";
	}
      else
	cout << " ";
	++c;
      }
    }
    cout << endl;
  }


  // 2-6
  int i = 0;
  while(i<10){
    i += 1;
    std::cout << i <<std::endl;
  }

  //2-7
  for(int j = 10; j >= -5; --j){
    cout << j << endl;
  }

  //2-8
  
  //2-9
  cout << "enter 2 numbers" << endl;
  cout << "first number:";
  int first;
  cin >> first;
  cout << endl;
  cout << "second number:";
  int second;
  cin >> second;
  cout << ((first > second)?first:second); //note for the parenthesis
  //   cout << ((first > second)?first:second); this will print 0 or 1 !!!
  return 0;
}
