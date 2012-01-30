#include <iostream>

class WallStreet {
public:
  static WallStreet* Instance();
protected:
  WallStreet();
private:
  static WallStreet* _instance; //one and only one WallStreet*
};


WallStreet* WallStreet::_instance = 0;

WallStreet* WallStreet::Instance() {
  if ( _instance == 0){
    _instance = new WallStreet;
    std::cout << "WallStreet* is first created and only once" << std::endl;
  }
  std::cout << "WallStreet* is created" << std::endl;
  return _instance;
}

WallStreet::WallStreet() {}

int main()
{
  WallStreet::Instance();
}
