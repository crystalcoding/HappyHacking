#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;

int main()
{
  //cout >> name;
  cout << "enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "enter all your homework grades, followed by end-of-line: ";
  cout << "(C-d in unix, C-z in MS)";
  int count = 0;
  double sum = 0;

  double x = 0;
  while (cin >> x){
    ++count;
    sum += x;
  }
 
  streamsize prec = cout.precision(3);
  cout << "your final grade is " 
       << 0.2 * midterm + 0.4 * final + 0.4 * sum/count << endl;
  cout.precision(prec);

}
