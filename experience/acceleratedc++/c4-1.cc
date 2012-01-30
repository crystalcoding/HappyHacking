#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <algorithm>

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

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();
  if (size == 0){
    throw domain_error("median of an empty vector");

  }
  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

double grade (double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size() == 0){
    throw domain_error("student has done no homework");
  }
    return grade(midterm, final, median(hw));

}

istream& read_hw(istream& in, vector<double>& hw)
{
  if (in){
    hw.clear();
    double x;
    while(in >> x){
      hw.push_back(x); 
    }
    in.clear();
  }
  return in;
}

int main()
{
  cout << "please enter your first name: ";
  string name;
  cin >> name;
  cout << "hello, " << name << "!" << endl;
  
  cout << "please enter your midterm and final grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "enter all your homework grades, " 
          "followed by end-of-file: ";
  vector<double> homework;
  read_hw(cin, homework);

  try {
    double final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();
    cout << "your final grade is " << setprecision(3)
	 << final_grade << setprecision(prec) << endl;
  }
  catch (domain_error) {
    cout << endl << "you must enter your grades. " 
         "please try again" << endl;
    return 1;
  }


  return 0;
}
