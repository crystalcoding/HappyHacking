#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getline_test()
{
  ifstream in("test.txt");
  if (in){
    while(in.good()){
      //cout << (char)in.get();
      string str;
      getline(in, str);
      cout << str;
      cout << " good input" << endl;
    }
  }
}

//the >> operator is whitespace-delimited, not line-delimited.
void read_format_data()
{
  ifstream in("test.txt");
  if (in){
    while(in.good()){
      string str;
      string second;
      in >> str >> second;
      cout << str << "(process)" << second;
      cout << endl;
    }
      
  }
}

int main()
{
  //getline_test();
  read_format_data();
}
