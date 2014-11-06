#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
void get_type(T)
{
  cout << "unknown type";
}

template <>
void get_type(int)
{
  cout << "int type";
}

template <>
void get_type(char)
{
  cout << "char type";
}

template <>
void get_type(float)
{
  cout << "float type";
}

template <>
void get_type(double)
{
  cout << "double type";
}

inline int const max(int a, int b)
{
  cout << "inline int const& max(int a, int b)";
  get_type(a);
  cout << endl;
  return a>b?a:b;
}

template <typename T>
inline T const max(T const a, T const b)
{
  cout << "inline T const max(T const a, T const b)";
  get_type(a);
  cout << endl;
  return a>b?a:b;
}

int main()
{
  ::max(10,5);       //int, nontemplate
  ::max<>(10,5);     //int, want to use the template, 
  ::max(7.0, 4.2);   //double
  ::max(7.0f, 4.2f); //float
  ::max('a', 'b');   //char
  ::max<double>(1,1); //double, explicity specify type of T
  ::max('a', 42.7);  //int, nontemplate
}
