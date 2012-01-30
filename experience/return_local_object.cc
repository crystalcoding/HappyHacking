#include <iostream>
#include <string>
using namespace std;

class candy{
public:
  candy();
  candy(const string &name, const string &assignable);
  candy(const candy &rhs);
  ~candy();
  candy& operator=(const candy &rhs);
  candy get_candy_object();
  string name;
  string assignable;
  void print_name();
 
};

candy::candy()
{
  name = "default name";
  assignable = "default assignable";
  cout << "constructor is called" << endl;
}
//candy::candy(string &s):name(s), assignable("default assignable")
candy::candy(const string &s, const string &assignable = "default assignable"):name(s), assignable(assignable)
{
  cout << name << " constructor is called" << endl;
}
candy::~candy()
{
  cout << name <<" candy destructor is called" <<
    " assignable name: " << assignable << endl;
}
candy::candy(const candy &rhs)
{
  assignable = rhs.assignable;
  cout << name << " copy constructor is called" << endl;
}

candy& candy::operator=(const candy &rhs)
{
  if(this != &rhs){
    cout << "candy copy assignment is called" << endl;
    assignable = rhs.assignable;
    if(name.length() == 0){
      name = "no name (since \"=operator\")" ;
    }
    return *this;
  }
}

candy candy::get_candy_object()
{
  //candy c() will work?
  cout << "before candy c in get_candy_object()" << endl;
  candy c("little candy return", "little candy assign");
  cout << "before candy c return" << endl;
  
  return c;
}

void candy::print_name()
{
  cout << "print_name:" << name << endl;
}

int main()
{
  candy can1("can1", "can1_assign");

  candy tmp_candy("tmp_candy", "tmp_candy_assign");
  cout << "after tmp_candy" << endl;
  tmp_candy = can1.get_candy_object(); //invoke copy assignment
                                       //then destructor is called
                                       //no copy constructor is called...?
  cout << "after tmp_candy = can1.get_candy_object();"<< endl;
  candy can2(can1);

  cout << "before can2 = can1" << endl;
  can2 = can1;

  cout << "before candy can3 = can2" << endl;
  candy can3 = can2;
  cout << "ending..." << endl;
  
  //string s("abc");
  //cout <<  s.length();
}
