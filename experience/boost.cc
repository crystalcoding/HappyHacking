
/*******************************************************************
how to use boost library in freebsd

g++ fs.cc -I /usr/local/include/ /usr/local/lib/libboost_filesystem.a

or

g++ fs.cc -I /usr/local/include/ -L/usr/local/lib/ -lboost_filesystem

********************************************************************/
#include "boost/filesystem.hpp"

using namespace boost;

int main()
{
  filesystem::create_directory("foobar");
}
