#include <iostream>
#include <string>
using namespace std;

class SimpleEncryption {
 public:
  SimpleEncryption(int offset);
  string encrypt(string s);
  string decrypt(string s);
 private:
  int offset;
  char start;
  char end;
  char encrypt_char(char c);
  char decrypt_char(char c);
};
