//Find the most common string in a vector
//containg strings
//Complexity: nlogn (logn because map.find())
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
  vector<string> v; 
  v.push_back("test");
  v.push_back("bing");
  v.push_back("google");
  v.push_back("google");
  v.push_back("Google");
  v.push_back("acer");
  v.push_back("asus");
  v.push_back("aspire one");

  map<string, int> m;
  //cout << m[v[1]] << endl;


  string most_common_string = "";
  int most_common_count = 0;
  for (int i=0; i<v.size();i++)
    {
      if ( m.find(v[i]) != m.end()) {
	m[v[i]]++;
	if (m[v[i]] > most_common_count){
	  most_common_string = v[i];
	  most_common_count = m[v[i]];
	}
      }
      else{
	//m.insert(v[i], 0);
	m.insert(make_pair(v[i],0));
      }
    }

  for (map<string,int>::iterator pos = m.begin();
       pos != m.end(); ++pos){
    //cout << (*pos).first << "," << (*pos).second << " ";
    cout << pos->first << "," << pos->second << " ";
    cout << "\n";
  }

  cout << "most common string:" << most_common_string << "\n";
  cout << "most common count:"  << most_common_count << "\n";
}
