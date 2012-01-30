#include <vector>
#include <iostream>
#include <string>


using namespace std;

int main()
{
  string s;
  cin >> s;

  vector<char> vchar(s.length());
  for(int i = 0; i < vchar.size(); ++i){
    vchar[i] = s[i];
    //cout << vchar[i];
  }

  int count = 1;
  sort(vchar.begin(), vchar.end());
  for(int i = 0, j = 1; i < vchar.size(); ++i, ++j){
    //'at' will through exception?
    if ( j < vchar.size()){
      if (vchar[i] != vchar[j]){
	cout << vchar[i] << " count: " << count << endl;
	count = 1;
      }

      else ++count;
    }

    if ( j == vchar.size()){
      cout << vchar[i] << " count: " << count << endl;
    }
  }

}
