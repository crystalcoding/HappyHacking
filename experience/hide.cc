#include <iostream>
using namespace std;

class B{
public:
  void f(int);
  virtual void can_be_overwritten() { cout << "can_be_overwritten() called from base" << endl;}
  void mandatory_implementation() { cout << "mandatory_implementation() called from B" << endl;}
};

class D: public B{
public:
 void f(double);
  void can_be_overwritten() { cout << "can_be_overwritten() called from derive" << endl;}
};

int main()
{
  //important****************************************************
  D d;
  //d(1); //HIDING OCCURS //error, no match for call to D (int) ! 
  //important***************************************************

  d.can_be_overwritten(); //from D

  B b;
  b.can_be_overwritten(); //from B. 

  B* bptr = new D;
  bptr->can_be_overwritten(); //from D. 1. bptr is B, so search in B first.
                              //        2. the method is virtual, which means base class offers a default implementation, 
                              //           and the derived class might overwrite it, so
                              //        3. to check if derive class uses its own version of this virtual function, 
                              //           check the actual type of bptr, which is D (we create it with new D)
                              //        4. so the B pointer bptr is actual a type D, so we check if D overwrites the function
                              //        5. Yes, D has the same method can_be_overwritten(), so use the D's method

  bptr->mandatory_implementation(); //from B, check B, and see the method is not virtual. stops here. 

  D* dptr = new D;
  dptr->mandatory_implementation(); //from B, //just use intuitive inheritance concept, D gets the mandatory method (not virtual) for free

  B* bptr_2 = new B;
  bptr_2->can_be_overwritten(); //from B. much simpler here, bptr_2 is actually type B, so just check its own class
}
