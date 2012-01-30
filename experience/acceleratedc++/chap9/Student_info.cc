#include <iostream>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::istream;
using std::vector;


//don't forget the qualifier in the constructor. 
Student_info::Student_info():midterm(0), final(0) 
{
}

Student_info::Student_info(istream& in)
{
  read(in); 
}

double Student_info::grade() const
{
  return ::grade(midterm, final, homework);
}

bool compare(const Student_info& s1, const Student_info& s2)
{
  return s1.name() < s2.name();
}

//no qualifier Student_info cause it's not in the class definition?

//ahha, pass by value, it's COPY! using pass by reference to correct it. 
istream& read_hw(istream& in, vector<double>& hw)
{
  if(in){
    hw.clear();

  double x;
  while( in >> x){
    hw.push_back(x);
    std::cout << "push back a hw grade" << std::endl;
    std::cout << "homework.size(): " << hw.size() << std::endl;
  }
    in.clear();
  }
  return in;
}

istream& Student_info::read(istream& in)
{
  in >> n >> midterm >> final;
  read_hw(in, homework);
  return in;
}
