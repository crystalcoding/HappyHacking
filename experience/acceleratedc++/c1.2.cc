#include <iostream>
#include <string>

int main()
{
  std::cout << " please enter your name: ";
  std::string name;
  std::cin >> name;

  const std::string greeting = "Hello, " + name + "!";

  const std::string spaces(greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";

  const std::string first(second.size(), '*');

  std::cout << std::endl;
  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first <<std::endl;



  //1-1
  const std::string hello = "Hello";
  const std::string message = hello + ", world" + "!";
  std::cout << message << std::endl;



  //1-6
  std::cout << "what is your name?";
  //std::string name;
  std::cin >> name;
  std::cout << "hello, " << name
	    << std::endl << "and what is yours? " ;
  std::cin >> name;
  std::cout << "hello, " << name
	    << "; nice to meet you too !" << std::endl;

  return 0;
}
