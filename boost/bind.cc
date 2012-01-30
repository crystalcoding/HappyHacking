//g++ bind.cc -I/usr/local/include
#include <iostream>
#include <string>
#include "boost/bind.hpp"
using namespace std;

template <typename myhandler>
void handler(myhandler hd)
{
  hd("passed from the handler");
}

class print {
public:
  print()
  {
    //calling a member function , remember the implicit this argument
    handler(boost::bind(&print::myprint, this));

   }
  void operator()() {}
  void myprint()
  {
    string s("using  member fuction(from function object) with boost::bind");
    int i = 5;
    cout << s << ", and its int: " << i << endl;
  }
};

void print2(string s, int i) 
{
    cout << "print string:" << s << ", and its int: " << i << endl;
}

void print3(string& s, int i)
{
   cout << "print string:" << s << ", and its int: " << i << endl;
}


int main(int argc, const int* argv[])
{
  //boost::bind(print2, "abc", 3); // no output
  //boost::bind(print2, "abc", 3)();
  //boost::bind(print2, "abc", 3)("aaa"); //"aaa" won't affect it
  //boost::bind(print2, _1, 3)("aaa");//"aaa" replaced _1
  //boost::bind(print2, _1, 3)("bbb","ccc", 5); //"ccc" and 5 are ignored
  //handler(boost::bind(print2, "abc", 3)); //print, abc, 3
  //handler(boost::bind(print2, _1, 3)); //"passed form the handler", 3
  //handler(boost::bind(print3, string("def"), 3)); //"def", 3
  print p; //"abc", 3
}
