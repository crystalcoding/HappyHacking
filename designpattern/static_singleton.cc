#include <iostream>
using namespace std;

class single {
public:
  static single* get_instance()
  {
    //local static only get called the first time
    // subsequent call to get_instance() will just return!
    static single* local_static_single = new single;
    return local_static_single;
  }
 
  void  print() {cout<<"print"<<endl;}

private:
  //private construction, assignment, etc
  single() {cout<<"single constructor called"<<endl;}

  //no implementation, so even friend will fail at link-time
  single(const single&); 
  single& operator=(const single&);
};

int main()
{
  //only one single instance is constructed!
  single* mysingle  = single::get_instance();
  single* mysingle2 = single::get_instance();
  single* mysingle3 = single::get_instance();
  mysingle->print();
}
