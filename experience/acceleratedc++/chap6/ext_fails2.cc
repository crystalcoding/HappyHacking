#include <algorithm>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::stable_partition;

vector<Student_info> ext_fail2(vector<Student_info>& s)
{
  vector<Student_info>::iterator itr =
    stable_partition(s.begin(), s.end(), pgrade);
  vector<Student_info> fail(itr, s.end());
  s.erase(itr, s.end());

  return fail;  
}
