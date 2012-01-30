//g++ eissh.cc -I/usr/local/include -L/usr/local/lib/ -lboost_regex
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <boost/regex.hpp>
#include <boost/foreach.hpp>
using namespace std;

struct hacker {
  string ip;
  int tries;
};
int main()
{
  ifstream in("auth.log");
  if (!in)  "can't open log\n";
  string line;
  size_t found;
  map<string, int> hacker_map;
  boost::regex pat("\\d+\\.\\d+\\.\\d+\\.\\d+");
  while (getline(in, line)){
    found = line.find("Invalid");
    if (found != string::npos) {
      boost::smatch matches;
      if (boost::regex_search(line, matches, pat)){
	//cout << matches[0] << endl;
	  if (hacker_map[matches[0]] > 0){	
	      ++hacker_map[matches[0]];
	  }
	  else {
	    hacker_map[matches[0]] = 1;
	  }
	}
    }       
  }

  typedef pair<string, int> pair_t;
  BOOST_FOREACH(pair_t p, hacker_map) {
    cout << p.first << endl;
    cout << p.second << endl;
  }
}
