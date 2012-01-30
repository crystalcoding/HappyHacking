#include <iostream>
using namespace std;



int main()
{
  int *p;
  int x = 1;
  p = &x;
 
  cout << &p << endl;
  cout << *p++ << endl; //print 1
  cout << x << endl;
  cout << &p << endl;

  x = 1;
  p = &x;
   
  cout << &p << endl;
  cout << *(p++) << endl;
  cout << x << endl;
  cout << &p << endl;

  x = 1;
  p = &x;
   
  cout << &p << endl;
  cout << *(p++) << endl;
  cout << x << endl;
  cout << &p << endl;
 
  x = 1;
  p = &x;

  cout << &p << endl;
  cout << (*p)++ << endl;
  cout << x << endl;
  cout << &p << endl; 

  //p = p + 1;
  //cout << &p;
  //cout << *p;

  int y[] = {1, 3};
  int *pp = &y[0];

  //see what happen
  //cout << (*pp)++ << endl;  //print 1, since post increment side-effect
  //cout << *pp << endl;      //print 2? why not 1? since it still points
                              //to y[0], but y[0] is not 2 !
  
  //see what happen
  //cout << ++(*pp) << endl;    //print 2, since pre-increnemtn side-effect
  

  //see what happen
  //cout << *pp++ << endl; //print 1
  //cout << *pp << endl; //print 3



  //see what happen
  //cout << *++pp << endl; //print 3
  //more
  //cout << *(++pp) << endl; //print 3



  //see what happen
  //cout << ++*pp << endl; //print 2
  //see what happen
  //cout << ++(*pp) << endl; //print 2


  //more  The following two are the same 
  //cout << *pp++ << endl; //print 1
  //more
  //cout << *(pp++) << endl; //print 1
  //cout << y[0] << endl; //print 1
  //more =======================================
  //cout << (*pp)++ << endl; //still print 1 !!!!!but now y[0] = 2 !!!!
  //cout << y[0] << endl; //now y[0] = 2
  //==============================================
  
  /*
  The parentheses dictate precedence but not the sequence.  The
incrementing performed by the ++ is a side effect.  The result however
does not depend on the side effect.

Think in terms of expressions.  Each expression evaluates to a value.
Some expressions also have side effects.

*p++ and *(p++) are exactly the same.

        The p++ is evaluated first, either due to the right to left
associativity or to the parentheses (the result is the same).  This
evaluation produces the value in p before it is modified.

        p++ also has a side effect (namely, incrementing p).  We have no
guarantee when that side effect will take place.  All we know for sure
is that it will occur sometime before or at the next sequence point.
We also don't care.

        The * operator dereferences the result of the previous evaluation.
The operator and its operation are completely unaffected by the side
effect discussed above.  It may have occurred already (p may be
incremented) or it may not have.  The * operator is not dereferencing
p.  It is dereferencing the value produced by the first evaluation
(which happens to be the unmodified value of p). 
*/
}
