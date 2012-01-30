#include <algorithm>
#include "Student_info.h"
#include "grade_check.h"

using std::find;

bool did_all_homework(const Student_info& student)
{
  return (find(student.homework.begin(), student.homework.end(), 0)
	  == student.homework.end());
}
