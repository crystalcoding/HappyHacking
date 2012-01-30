#include <iostream>

class bound_err {
public:
  std::string what;
  
  bound_err(const std::string & i_what);
};

bound_err::bound_err(const std::string &i_what): what(i_what)
{
}

int main()
{
  try{
  if (1<5)
    throw bound_err("waza");
  }
  catch (bound_err &err){
    std::cout << err.what;
  }
 
  std::cout << "lala";
  return 0;
}
