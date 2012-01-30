#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;

int main()
{

  //testing the mid of the vector index
  vector<double> v(3);
  v[0] = 15;
  v[1] = 16;
  v[2] = 17;
  typedef  vector<double>::size_type my_sz;
  my_sz sss = v.size();
  cout << "sss: " << sss << endl;
  cout << "sss/2: " << sss/2 << endl;
  my_sz mymid = sss/2;
  cout << "mymid: " << mymid << endl;
  cout << v[mymid] << endl;
  //////////////////////////////////////


  //cout >> name;
  cout << "enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "enter all your homework grades, followed by end-of-line: ";
  cout << "(C-d in unix, C-z in MS)";
  int count = 0;
  double sum = 0;

  double x = 0;
  vector<double> homework;
  while (cin >> x) {
    homework.push_back(x);
  }

  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();
  if(size==0){
    cout << endl << " you must enter your grade, please try again" << endl;
    return 1;
  }

  sort(homework.begin(), homework.end());
  vec_sz mid = size/2;
  double median;
  median = size%2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

 
  streamsize prec = cout.precision(3);
  cout << "your final grade is " 
       << 0.2 * midterm + 0.4 * final + 0.4 * sum/count 
       << setprecision(prec) << endl;
  

}
