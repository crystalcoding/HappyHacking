#include <iostream>

using namespace std;

class OS {
public:
  OS();
  virtual ~OS();
  void boot();
  void shutdown();
  virtual void clean_up();

 

private:

};

OS::OS()
{
}

OS::~OS()
{
}

void OS::boot()
{
  cout << "starting..." << endl;
}

void OS::shutdown()
{
  cout << "shutting down..." << endl;
}

void OS::clean_up()
{
  cout << "generic OS clean up..." << endl;
}

class freebsd: public OS {
public:
  freebsd();
  void freebsd_start();
  void freebsd_shutdown();
  void clean_up();
};

freebsd::freebsd()
{

}

void freebsd::freebsd_start()
{
  //OS::boot();
  boot(); //no boot() in freebsd, 
          //compiler will try to look
          //for it's parent.
}

void freebsd::freebsd_shutdown()
{
  //OS::shutdown();
  shutdown(); //no shutdown() in freebsd, 
              //compiler will try to look 
              //for it's parent
}

void freebsd::clean_up()
{
  cout << "freebsd OS clean up..." << endl;
}

int main()
{
  freebsd fbsd;
  fbsd.freebsd_start();
  fbsd.freebsd_shutdown();
  fbsd.clean_up();

  OS *os = new freebsd();
  os->clean_up(); //ah ha, will call os 
                  //if clean_up() is not  
                  // virtual
  delete os;

}
