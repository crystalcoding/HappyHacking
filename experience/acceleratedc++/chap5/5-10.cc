#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl;
using std::vector; using std::string;

vector<string> get_palindrome_list(const vector<string>& v)
{
  vector<string> palindrome;
  for (vector<string>::const_iterator itr = v.begin();
       itr != v.end(); ++itr) {
    string::size_type i = 0;
    string::size_type j = itr->size() -1;
    while ( i <= j && i < itr->size()){
      if ( (*itr)[i] == (*itr)[j]){
	++i;
	--j;
      }
      else{
	break;
      }
    }

    if ( i >= j){
      palindrome.push_back(*itr); 
      //cout << "found a palindrome: " << *itr << endl;
    }
  }

  return palindrome;
}

int main()
{

  vector<string> sample_dictionary;
  sample_dictionary.push_back("abc");
  sample_dictionary.push_back("adfasfasdfasdfa");
  sample_dictionary.push_back("elele");
  sample_dictionary.push_back("aba");
  sample_dictionary.push_back("elale");
  sample_dictionary.push_back("abcdefglllgfedcba");

  vector<string> v = get_palindrome_list(sample_dictionary);
  for (int i = 0; i < v.size(); ++i){
    cout << v[i] << endl;
  }
  return 0;
}
