#include <iostream>
using namespace std;

int main()
{
  for(char c = 'a'; c<= 'z'; ++c)
    {
      cout << c << " ";
    }

  for(char c = 97; c<=122; ++c)
    {
      cout << hex << c << " ";
    }

  for(int c = 97; c<=122; ++c)
    {
      cout << hex << c << " ";
    }

  for(int c = 97; c<=122; ++c)
    {
      cout << oct << c << " ";
    }
}
