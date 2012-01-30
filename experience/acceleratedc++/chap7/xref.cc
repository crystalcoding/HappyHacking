#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "split.h"

using std::map; using std::vector;
using std::string; using std::cout; 
using std::cin; using std::endl;
using std::istream;

map<string, vector<int> > xref(istream& in,
			       vector<string> find_word(const string& s) = split)
{
  map<string, vector<int> > ret;
  int line_num = 0;
  string s;
  while ( getline(in, s)){
    vector<string> split_s = find_word(s);    
    for(vector<string>::iterator itr = split_s.begin();
	itr != split_s.end(); ++itr) {
      ret[*itr].push_back(line_num);
    }

    ++line_num;

  }

  return ret;
}

int main()
{
  map<string, vector<int> > xmap = xref(cin);
  for(map<string, vector<int> >::iterator itr = xmap.begin();
      itr != xmap.end(); ++itr){
    cout << endl << "word: " << itr->first << " appears on line: ";
    
    for(vector<int>::iterator vitr = itr->second.begin();
	vitr != itr->second.end(); ++vitr){
      cout << " " << *vitr ;
    }
      
  }

  cout << endl;
  return 0;
}
