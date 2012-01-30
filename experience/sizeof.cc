#include <iostream>
#include <limits>
using namespace std;

int main()
{
  cout << "sizeof(char)"<< sizeof(char) << endl;
  cout << "(char)largest"<<numeric_limits<char>::is_signed<<endl;
  cout << "sizeof(bool)"<<sizeof(bool) << endl;
  cout << "sizeof(short)"<<sizeof(short) << endl;
  cout << "sizeof(long)" <<sizeof(long) << endl;
  cout << "sizeof(int)"<<sizeof(int) << endl;
  cout << "(int)largest<<"<<numeric_limits<int>::max() << endl;
  cout << "sizeof(int*)"<<sizeof(int*) << endl;
  cout << "sizeof(double)"<<sizeof(double) << endl;
  cout << "sizeof(double*)" <<sizeof(double*) << endl;
  cout << "sizeof(float)" <<sizeof(float) << endl;
  enum day {MONDAY, TUESDAY, WEDNESDAYp};
  cout << "sizeof(enum day {MONDAY, TUESDAY, WEDNESDAY}"<<sizeof(day) << endl;
}
