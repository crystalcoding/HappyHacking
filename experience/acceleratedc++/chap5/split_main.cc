#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using std::getline;
using std::string;
using std::cout; using std::endl;
using std::vector;
using std::cin;

int main()
{
  string s = "";

  vector<string> v;
  while(getline(cin, s)){
  v = split(s);

  for(vector<string>::iterator itr = v.begin();
      itr != v.end(); ++itr){
    cout << *itr << endl;
  }
  }
  return 0;
}

