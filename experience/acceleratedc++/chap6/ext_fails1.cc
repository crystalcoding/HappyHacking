#include <algorithm>
#include <vector>

#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::remove_copy_if;
using std::remove_if;
using std::back_inserter;

vector<Student_info> ext_fail1(vector<Student_info>& s)
{
  vector<Student_info> fail;
  remove_copy_if(s.begin(), s.end(), 
		 back_inserter(fail), pgrade);
  s.erase((remove_if(s.begin(), s.end(), fgrade ), s.end()));
  return fail;
	  
}
