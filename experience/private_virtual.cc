#include<iostream>
using namespace std;
class base {
public:
  void printprint() { printme();}
private:
  //you can't call except base, but you can redefined it
  virtual void printme() {cout << "base printme!" << endl;}
};

class derive: public base {
  void printme() {cout << "derive printme!" << endl;}

};

int main()
{
  base b;
  derive d;
  b.printprint();
  d.printprint();
  
}

