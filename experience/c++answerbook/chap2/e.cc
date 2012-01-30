#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  char *a;

  vector<int> v(10);
  vector<int>& v_ref = v;
  cout << v_ref[1] << endl;

  vector<string> s(10, "string");
  vector<string>* s_pt = &s;
  cout << (*s_pt)[2] << endl;

  char aa;
  char* paa = &aa;
  //char* ppaa = &paa; wrong
  char **ppaa = &paa;

  int i = 5;

  int const *pt = &i;

}
