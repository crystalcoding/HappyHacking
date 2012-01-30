#include <iostream>
using namespace std;

int main()
{
  enum book { CPlusPlus, CSharp, C };
  book Book = C;
  cout << Book << endl; //print 2
}
