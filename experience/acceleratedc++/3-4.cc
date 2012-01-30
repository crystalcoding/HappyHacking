#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  //cout << 5/0; //Floating point exception (core dumped)
  vector<string> s;
  string tmpstring;
  while (cin >> tmpstring){
    s.push_back(tmpstring);
  }
  string longest = "";
  string shortest = "";
  for(int i = 0; i < s.size(); ++i){
    if (s[i].length() > longest.length()){
      longest = s[i];
    }
  }
  shortest = longest;
  for(int i = 0; i < s.size(); ++i){
    if (s[i].length() < shortest.length()){
      shortest = s[i];
    }
  }

  cout << "longest string: " << longest << endl;
  cout << "shortest string: " << shortest << endl;



}
