#include <iostream>
using namespace std;

#include <string>

//void f(int);
void f(const char*){}
int main()
{
  f("Hello world!"); //argument type is "const char*"
}
