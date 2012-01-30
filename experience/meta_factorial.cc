#include <iostream>

template<int n>
class Factorial {
 public:
  enum { val = Factorial<n-1>::val * n };
};

template<> 
class Factorial<0> {
 public:
  enum { val = 1};
};

int main()
{
  std::cout << Factorial<12>::val ; //print 479001600
}

//  since template will need to instantiate Factorial<11> before Factorial<12>, 
//    and Factoria<10> before Factorial<11>... all the way to Factorial<0>, 
//    we obtain the answer, Factorial<12> = 479001600, at compile time ! 
