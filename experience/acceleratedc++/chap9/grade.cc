#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;

#include "grade.h"
#include "median.h"

double grade(double midterm, double final, double homework)
{
  return 0.2*midterm + 0.4*final + 0.4*homework;
}

//don't forget the const ! you declare const in the header file
//or you get this
/*
/tmp/ccfXouNk.o: In function `Student_info::grade() const':
Student_info.cc:(.text+0x418): undefined reference to `grade(double, double, std::vector<double, std::allocator<double> > const&)'
collect2: ld returned 1 exit status
 */
double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("student has no homework");
  return grade(midterm, final, median(hw));
}
