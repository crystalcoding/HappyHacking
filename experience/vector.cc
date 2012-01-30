#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //sort
using namespace std;


//take the for loop, you need typename so cit becomes a type
template <typename T>
void printVector(vector<T>& theVector)
{
  for(typename vector<T>::const_iterator cit = theVector.begin();
      cit != theVector.end(); ++cit)
    {
      cout << *cit << " ";
    }
  cout << endl << "(finished printing vector)" << endl;
}

int main()
{
  vector<char> myv(27); //note: vector<char> myv[27] is 27 empty myv[] !
                        //so, myv(27) != myv[27]                    
  for(char c='a'; c<='z';c++)
    myv.push_back(c);

  printVector(myv);

  for(vector<char>::reverse_iterator cit = myv.rbegin();
      cit != myv.rend(); ++ cit)
    cout << *cit;

  cout << endl;

  vector<string> myvs(5);
  string input;
  for(int i=0; i<5; i++) //if using iterator, vector will grow itself~
  {
    cin >> input;
    myvs.push_back(input);
  }

  //a hack that get rid of the new line character
  myvs.erase(myvs.begin(), myvs.begin()+5);

  sort(myvs.begin(), myvs.end());
  

  cout << "fruit starts with 'a'" << endl;
  for(vector<string>::const_iterator cit = myvs.begin();
      cit != myvs.end(); ++cit)
    {
      if((*cit)[0] == 'a') //note [] has higher precedence than *, so we need()
	cout << *cit << endl;
    }
 
  printVector(myvs);

   cout << "vector size=" << myvs.size();

  vector<string>::iterator sentinel;
  //don't use const_iterator if we want to modify stuff
  for(vector<string>::iterator cit = myvs.begin();
      cit != myvs.end(); ++cit)
    {
      cout << "erase function iterator cit=" << *cit << endl;
      if((*cit)[0] != 'a')
	{
	  cout << "erase at " << *cit << endl;
          sentinel = cit;
	  break;
	}	
    }
  myvs.erase(myvs.begin(), sentinel);
  cout << "sentinel=" << *sentinel;

  cout << "No more food starts with 'a'" << endl;
  printVector(myvs);

  vector<int> reserv_v;
  //reserv_v.reserve(80);
  for(int i = 0; i < 80; ++i)
    {
      reserv_v.push_back(i);
    }
  cout << "reesrv_v.capacity()=" << reserv_v.capacity() << endl;

  //reserv_v.push_back(81);
  //cout << "reesrv_v.capacity()=" << reserv_v.capacity() << endl;
}
