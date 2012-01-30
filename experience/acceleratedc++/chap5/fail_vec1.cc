#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

vector<Student_info>  extract_fail(vector<Student_info>& s)
{
  vector<Student_info> pass, fail;
  
  for (vector<Student_info>::size_type i = 0;
       i < s.size(); ++i){
    if (fgrade(s[i])){
      //fail.push_back(s); wrong
      fail.push_back(s[i]);
    }
    else{
      //pass.push_back(s); wrong
      fail.push_back(s[i]);
    }
  }

  s = pass;
  return fail;
}
