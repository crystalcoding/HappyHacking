#include <iostream>

template<typename mykind>
mykind bigger(mykind a, mykind b)
{
  if (a>b)
    return a;
  else 
    return b;
}

int bigger(int a, int b)
{
  std::cout << "bigger() not using template "<< std::endl;
}


//a template class point
template<typename T>
class point {
public:
  point(T iniY):y_(y_ = iniY)
  {std::cout << "point(T iniY) constructed" << std::endl;}
  T y() const { std::cout << "T y() is called";  return y_ ;}
  T& y()      { std::cout << "T& y() is called"; return y_ ;}

private:
  T y_;
};

template<>
class point<double>
{
public:
  point(double iniX): x_(x_ = iniX)
  {std::cout << "template specialization point(double) constructed" << std::endl;}
  double x() const {std::cout << "double x() is called"<< std::endl; return x_; }

private:
  double x_;
};

template<typename lala, typename lala2>
void no_param(lala a, lala b, lala2 c ) //you have to use all the Type????
{
  std::cout << "print I=" << 56666 << std::endl;
}
  

int main()
{
  std::cout << bigger(5, 6) << std::endl;
  std::cout << bigger(5.5, 6.6) << std::endl;

  point<int> p(3);
  std::cout << "p.y()=" << p.y() << std::endl;  //why calling T& y()
  
  point<double> pdouble(1.234567);
  std::cout << "pdouble.x()=" << pdouble.x() << std:: endl;

  std::cout << "no_param()=" << std::endl;
  no_param(10,6, 3);

  std::cout << std::endl;
}
