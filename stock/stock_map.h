#ifndef STOCK_MAP_H
#define STOCK_MAP_H

#include <iostream>
#include <map>
#include <string>

class stock_map
{
 public:
  stock_map();
  void  print_stocks();
  std::map<std::string, int> m_stock_map;



};



#endif
