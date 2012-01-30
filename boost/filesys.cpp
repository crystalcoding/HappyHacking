#include "boost/filesystem.hpp"
#include <iostream>

namespace fs = boost::filesystem;


int main()
{
  fs::create_directory("foobar");
  
  return 0;
}
