#include <iostream>

int main()
{

  int i = 5;
 
  //this will print "true"
  (i == 5)?std::cout<<"true":std::cout<<"false";

  std::cout<<std::endl;

  //this will print "false"
  int j;
  (i = j) ? std::cout<<"true":std::cout<<"false";
  
  std::cout<<std::endl;

  //this will print "false"
  i?std::cout<<"true":std::cout<<"false";
}
