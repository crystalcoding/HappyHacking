#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"

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

  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)){
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
    }

  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0;
       i != students.size(); ++i){
    cout << students[i].name
	 << string(maxlen + 1 - students[i].name.size(), ' ');

    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec);
    }
    catch (domain_error e){
      cout << e.what();
    }
  }

  return 0;
}
