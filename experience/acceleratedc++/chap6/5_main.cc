#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <algorithm>

#include "grade.h"

#include "Student_info.h"

#include "analysis.h"

using std::vector;
using std::domain_error;
using std::istream; //!!! istream is part of std or you will get
//error: expected constructor, destructor, or type conversion before '&' token

using std::ostream;
using std::endl;
using std::sort;
using std::streamsize;
using std::string;
using std::cin;
using std::cout;
using std::setprecision;
using std::max;

int main()
{

  Student_info student;
  vector<Student_info> did, didnt;

  while(read(cin, student)){
    if( did_all_hw(student)){
      did.push_back(student);
    }
    else{
      didnt.push_back(student);
    }
  }

  if (did.empty()) cout << "did is empty";
  if (didnt.empty()) cout << "didnt is empty";


  return 0;
}
