#include <iostream>
#include "Str.h"

using std::ostream;
using std::istream;

ostream& operator<<(ostream& os, const Str& s)
{
  for (Str::size_type i = 0; i != s.size(); ++i)
    os << s[i];
  return os;
}

istream& operator>>(istream& is, Str& s)
{
  s.data.clear();
  
  char c;
  while (is.get(c) && isspace(c)) {
      ;
    }
    if(is) {
      do s.data.push_back(c);
      while(is.get(c) && !isspace(c));

      if (is)
       is.unget();
    }

 return is;
}

Str operator+(const Str& x, const Str& y)
{
  Str ret;
  //ret += x;
  ret = x;  // note: in Vec.h  Vec& operator=(const Vec& rhs)
  ret += y;
  return ret;
}
