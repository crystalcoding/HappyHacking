#include <iostream>

class test {
public:
  std::string name;

  void printme();


};

void test::printme()
{
  std::cout << "print stuff";
}

int main()
{
  test t;
  t.printme();
}
