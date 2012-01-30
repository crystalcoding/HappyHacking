#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

vector<Student_info>  extract_fails(vector<Student_info>& s)
{
  vector<Student_info> fail;
  
  vector<Student_info>::size_type i = 0;
  while( i != s.size()){ //so '<' works too?
    if (fgrade(s[i])){
      fail.push_back(s[i]);
      s.erase(s.begin()+i); //why s.erase(i) doesn't work?
    }
    else{
      ++i;
    }
  }

  return fail;
}
