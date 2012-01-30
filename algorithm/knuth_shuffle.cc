#include <iostream>
#include <cstdio> //srand(),rand()
#include <ctime>  //time
using namespace std;

// it's still a bad shuffle (biased) because it has cross-over
// overshuffle. 
void shuffle_wrong(int a[], int len)
{
  srand(time(NULL)); //rand() between in each second
  for (int i=0; i<len; ++i){
    int rand_index = rand() % (len - i);
    cout << "len-i:" << len-i << ". " << "rand_index:" << rand_index << endl;
    cout << "a[rand_index]:" << a[rand_index] << endl;
    cout << "a[i]:" << a[i] << endl;
 
    int t = a[i];
    a[i] = a[rand_index];
    a[rand_index] = t;
  }

  for (int j=0;j<len;++j){
    cout << a[j];
  }
  cout << endl;
}

// once picked, we have one less choice to permute
// better distribution here because it follow the
// right way to permute a sequence (n*(n-1)*(n-2)...)
void shuffle2(int a[], int len)
{
  srand(time(NULL)); //new rand() between in each second
  for (int i=len-1; i>0; --i){
    int rand_index = rand() % (i+1);
    cout << "i+1:" << i+1 << ". " << "rand_index:" << rand_index << endl;
    cout << "a[rand_index]:" << a[rand_index] << endl;
    cout << "a[i]:" << a[i] << endl;
 
    int t = a[i];
    a[i] = a[rand_index];
    a[rand_index] = t;
  }

  for (int j=0;j<len;++j){
    cout << a[j];
  }
  cout << endl;
}

int main()
{
  int a[] = {1,2,3,4,5,6,7,8,9};
  //shuffle(a, sizeof(a)/sizeof(a[0]));//wrong version
  shuffle2(a,sizeof(a)/sizeof(a[0]));
}
