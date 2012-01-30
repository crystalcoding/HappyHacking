#define MYCODE(e) e
#define EACCESS 1234
#include <iostream>
using namespace std;

int main()
{
  
  enum basic_errors
  {
    access_denied = MYCODE(EACCESS)
  };
 
  basic_errors be;
  be = access_denied;
  cout << be << endl;
  return 0;
}
