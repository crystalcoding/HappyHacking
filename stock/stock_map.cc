#include "stock_map.h"

using namespace std;

stock_map::stock_map()
{

}

void stock_map::print_stocks()
{

}

int main()
{
  stock_map sm;
  
  sm.m_stock_map["redsea"] = 50;
  sm.m_stock_map["acer"] = 60;
  sm.m_stock_map["asus"] = 70;

  for(map<string, int>::iterator i =sm.m_stock_map.begin(); i != sm.m_stock_map.end(); ++i)
    {
      cout << i->first << ":" << i->second <<endl;
    }

  return 0;
}
