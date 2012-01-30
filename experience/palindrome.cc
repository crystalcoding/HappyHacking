#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;
  
  size_t s_start;
  size_t s_end;

  if(s.size() < 0)
    {
      cout << s << " is not a palindrome." << endl;
    }
  else
    {
      s_start = 0;
      s_end = s.size() -1 ;
      //cout << "s_start:" << s_start << endl;
      //cout << "s_end:" << s_end << endl;
      for (; s_start <= s_end ; ++s_start, --s_end)
	{
	  if (s[s_start] != s[s_end])
	    {
	      //cout << "s["<< s_start << "]=" << s[s_start] << endl;
	      //cout << "s["<< s_end   << "]=" << s[s_end] << endl;
	      cout << s << " is not a palindrome." << endl;
	      return 0;
	    }
	}

      //pass the check, it is a palandrom
      cout << s << " is a palindrome." << endl;
      return 0;
    }
}
