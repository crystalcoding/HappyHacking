#include <iostream>
#include "pic.h"


using std::cout;
using std::endl;
using std::string;
using std::vector;

string::size_type width(const vector<string>& v)
{
  //typedef string::size_type max_length;
  /*pic.cc:13: error: expected unqualified-id before '=' token
   pic.cc:17: error: expected primary-expression before ')' token
   pic.cc:18: error: expected unqualified-id before '=' token
   pic.cc:21: error: expected primary-expression before ';' token
  */
  string::size_type max_length;
  max_length = 0;

  for(vector<string>::const_iterator itr = v.begin();
      itr != v.end(); ++itr){
    if ((*itr).size() > max_length){
      max_length = (*itr).size();
    }
  }
  return max_length;
}

vector<string> frame(const vector<string>& v)
{
  vector<string> ret;
  string::size_type max_length = width(v);
  
  string edge(max_length+4, '*');
  ret.push_back(edge);
  for(vector<string>::const_iterator itr = v.begin();
      itr != v.end(); ++itr){
    const string s = "* " + *itr 
      + string(max_length - (*itr).size(), ' ')
      + " *";
    ret.push_back(s);    
  }

  ret.push_back(edge);

  return ret;  
}

vector<string> vcat(const vector<string>& top, 
		    const vector<string>& bottom)
{
  vector<string> ret;

  for (vector<string>::const_iterator itr
	 = top.begin(); itr != top.end();
       ++itr){
    ret.push_back(*itr);
  }

  ret.push_back(" ");
  for (vector<string>::const_iterator itr 
	 = bottom.begin(); itr != bottom.end();
         ++itr){
    ret.push_back(*itr);
  }
  // it will core dump without return the frame
  return frame(ret);
}

vector<string> hcat(const vector<string>& left,
		    const vector<string>& right)
{
  vector<string> ret;

  string::size_type l_max_length = width(left);
  string::size_type r_max_length = width(right);  

  vector<string>::const_iterator l_iter = left.begin();
  vector<string>::const_iterator r_iter = right.begin();

  string s;
  while ( l_iter != left.end() || r_iter != right.end()){

    if ( l_iter != left.end()){
      s = *l_iter + string(l_max_length - l_iter->size() + 1, ' ');
      ++l_iter;

      if( r_iter != right.end()){
	s += *r_iter + string(r_max_length - r_iter->size(), ' ');
	++r_iter;
	ret.push_back(s);
      }
      else {
	if( r_iter == right.end()){
	  s += string(r_max_length, ' ');
	}
	cout << "size of this row: " << s.size();
	ret.push_back(s);
      }
    }

    else {
      s = string(l_max_length + 1, ' ');
      s += *r_iter + string(r_max_length - r_iter->size(), ' ');
      ++r_iter;

      cout << "size of this row: " << s.size();
      ret.push_back(s);
    }
  }

  cout << "l max length: " << l_max_length << endl;
  cout << "r max length: " << r_max_length << endl;
  return frame(ret);
}

/*
int main()
{
  
  int array[3] = {1, 2, 3};

  int index = 0;
  int first = array[index++];
  cout << "index: " << index << endl;
  cout << first << endl; // print 1

  index = 0;
  first = array[++index];
  cout << "index: " << index << endl;
  cout << first << endl; // print 2



}
*/
