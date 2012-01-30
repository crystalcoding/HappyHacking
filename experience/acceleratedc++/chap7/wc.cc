#include <map>
#include <iostream>
#include <string>
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
  cout << "???" ;
  map<string, int> m;
  string s;
  
  while ( cin >> s){
    cout << "Please enter a word" << endl;
    m[s] = m[s] + 1;
    //or, ++m[s];
  }
  for(map<string, int>::iterator itr = m.begin();
      itr != m.end(); ++itr){
    cout << "word: " << itr->first << " appears " << itr->second << " times."
	 << endl;
  }

  return 0;
}
