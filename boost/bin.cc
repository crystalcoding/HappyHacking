#include <boost/filesystem/operations.hpp>
#include <fstream>
#include <ostream>
#include <iostream>

using namespace std;
namespace fs = boost::filesystem;

int main()
{
  const int SZ = 100;
  int buff_total = 0;
  char buf[SZ];
  {
    //ifstream in("reply.gif");
    ifstream in;
    in.open("reply.gif", ios::out | ios::binary);
    ofstream out("replyout.gif");

    int total = sizeof in;

    while(total > 0) {
      in.read(buf, SZ);
      total -= SZ;
      cout << buf << endl;
      out << buf << "\n";  //put the new line back
      buff_total += sizeof buf;
    }
  }
  
  cout << "buff_total:" << buff_total << endl;
  fs::path p("reply.gif");
  cout << fs::file_size(p) << endl;

  fs::path p2("replyout.gif");
  cout << fs::file_size(p2) << endl;
}
