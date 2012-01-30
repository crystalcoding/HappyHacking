#include <iostream>

using namespace std;

class calc {
public:
  inline void calc_public() { cout << "calc_public() call" << endl; }
  inline void calc_public_call_private() {cout << "call private from public" << endl; }
private:
  inline void calc_private() { cout << "calc_private() call" << endl; }
};

int main()
{
  calc c;
  //c.calc_private(); can't call, calc_private() is private
  c.calc_public();
  c.calc_public_call_private();
}
