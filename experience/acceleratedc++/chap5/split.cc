#include <vector>
#include <string>
#include <cctype>

using std::string;
using std::vector;
using std::isspace;

vector<string> split(const string& s)
{
  vector<string> ret;

  typedef vector<string>::size_type string_size;
  string_size i = 0;
  string_size j = 0;

  string tmp_string;
  while( i < s.size()){

    while(i < s.size() &&  isspace(s[i])){
      ++i;
    }

    j = i;
    while( j < s.size() &&!isspace(s[j])){
	  ++j;
    }

    if( i != j){
      ret.push_back(s.substr(i, j-i));
      i = j;
    }


  }

  return ret;
}
