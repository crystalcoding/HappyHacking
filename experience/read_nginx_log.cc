#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <boost/regex.hpp>
#include <boost/foreach.hpp>

using namespace std;

int main()
{
  //g++ c.cc -lboost_regex -L/usr/lib/
  
  //ifstream in("access.log");
  ifstream in("access.log.1");
  //ifstream in("error.log");
  boost::regex pat("\\d*.\\d*.\\d*.\\d*");
  cout << "pattern:" << pat;

  string line;
  vector<string> v;
  map<string, int> m;
  map<string, int>::iterator it;
  map<int, string> sorted_m;

  while(getline(in, line)){
    boost::smatch matches;
    if( boost::regex_search(line, matches, pat)) {
      //cout << line;
      //cout << matches[0];
      //v.push_back(matches[0]);
      string m_match = matches[0];
      it = m.find(matches[0]);
      if (it == m.end()){
	m.insert(it, pair<string, int>(m_match, 1));
      } else {
	++(it->second);
      }
    }
  }
  //BOOST_FOREACH( string s, v) {
  //  cout << s << endl;
  //}

  //does not work
  //BOOST_FOREACH( map<string, int> item, m) {
  //  cout << item->first << "=> " << item->second << endl; 
  //}

  for (it=m.begin(); it!=m.end(); ++it) {
    //cout << it->first << "=> " << it->second << endl; 
    sorted_m.insert(pair<int, string>(it->second, it->first));
  }

  for (map<int, string>::iterator it=sorted_m.begin(); it!=sorted_m.end(); ++it) {
    cout << it->first << "=> " << it->second << endl; 
  }
}
