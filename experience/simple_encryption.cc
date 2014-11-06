#include <iostream>
#include "assert.h"
#include "simple_encryption.h"

//class that help rotate between ASCII 33~126
SimpleEncryption::SimpleEncryption(int offs)
  :offset(offs), start('!'), end('~')
{
}

string SimpleEncryption::encrypt(string s)
{
  string ret;
  for (string::iterator it=s.begin(); it!=s.end(); ++it) {
    ret += encrypt_char(*it);
  }
  return ret;
}

string SimpleEncryption::decrypt(string s)
{
  string ret;
  for (string::iterator it=s.begin(); it!=s.end(); ++it) {
    ret += decrypt_char(*it);
  }
  return ret;
}

char SimpleEncryption::encrypt_char(char c)
{
  //assume c is printable
  if ( (c+offset) > static_cast<int>(end)) {
    return (c+offset) - static_cast<int>(end) + 32;
  }
  return c+offset;
}

char SimpleEncryption::decrypt_char(char c)
{
  //assume c is printable
  if (c-offset < static_cast<int>(start)) {
    return 127 - (offset - (c - static_cast<int>(start)));
  }
  return c-offset;
}

int main()
{
  SimpleEncryption sm(80);

  char raw[256];
  cin.getline(raw, 256);
  cout << "original: " << raw << endl;

  string encrypted = sm.encrypt(raw);
  cout << "encrypted:" << encrypted << endl;
  string decrypted = sm.decrypt(encrypted);
  cout << "decrypted:" << decrypted << endl;

  //assert(encrypted==encrypted);
}
