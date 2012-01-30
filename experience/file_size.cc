#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ifstream in("vec.cc", ios::binary);
  //cout << sizeof(in) << endl;
 
  in.seekg(0, ios::end);
  int length = in.tellg();
  in.seekg(0, ios::beg);
  cout << length << endl;
 
  ofstream out("vec_cp.cc", ios::binary);
  if(in){
    cout << "good" << endl;
    out << in.rdbuf();
    out.close(); //close for stream! or you 
                 //cannot write later below
  }
  
  ifstream check("vec_cp.cc", ios::binary);
  check.seekg(0, ios::end);
  length = check.tellg();
  cout << length << endl;
  //cout << sizeof(out) << endl;
}
