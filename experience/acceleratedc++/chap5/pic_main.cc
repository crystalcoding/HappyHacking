#include <iostream>
#include <vector>
#include <string>


#include "pic.h"
#include "split.h"

using std::cout; using std::endl; using std::cin;
using std::getline;

using std::vector; using std::string;

vector<string> prepare_frame()
{
  vector<string> v;
  string s;
  getline(cin, s);
  v = split(s);
  return v;
}

int main()
{

  //5-7***************
  vector<string> empty_v;
  frame(empty_v);

  /////***************
  vector<string> v;
  v = prepare_frame();

  vector<string> v2;
  v2 = prepare_frame();
  
  //v = vcat(v, v2);
  v = hcat(v, v2);

  for(vector<string>::const_iterator itr = v.begin();
      itr != v.end(); ++itr){
    cout << *itr;
    cout << endl;
  }

  return 0;
}
