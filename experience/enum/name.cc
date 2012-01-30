#include <iostream>

namespace ns {
  enum my_enum { x, y, z }; //use ns::x, ns::y, ns::z, not ns::my_enum::x
                            //why? because my_enum is a type, 
                            //not a class or namespace

  int my_int = 3; //same logic, use ns::my_int, we don't use ns::int::my_int,                   //do we? 

  class my_class {
    public:
    my_class(my_enum);
  };
}

ns::my_class::my_class(ns::my_enum variable /*my_enum::x ? ns::x ? */)
{
  std::cout << "inside the constructor of my_class(my_enum x)" << std::endl;
  std::cout << variable << std::endl;
}

int main()
{
  ns::my_enum enu = ns::y; //need ns::y but not y only
  std::cout << enu << std::endl; //print 1

  ns::my_class my_class_instance_1 = ns::my_class(ns::x); //print 0
  ns::my_class my_class_instance_2 = ns::my_class(ns::y); //print 1

  ns::my_enum enu_2 = ns::z;
  ns::my_class my_class_instance_3 = ns::my_class(enu_2); //print 2

  //ns::my_class my_class_instance_4 = ns::my_class(ns:enum::x); //wrong, expect a primary expression

  //ns::my_class my_class_instance_5 = ns::my_class(ns::my_enum::x); //wrong, ns::my_enum is not a class or namespace

  //ns::my_class my_class_instance_6 = ns::my_class(ns::my_enum); //expected primary-expression


  //std::cout << ns::int::my_int << std::endl; //wrong, 
  std::cout << ns::my_int << std::endl; //print 3
}

