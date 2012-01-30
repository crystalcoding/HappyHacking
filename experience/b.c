#include <stdio.h>

int main()
{
  int MAXBUF = 5;
  char buf[MAXBUF];

  buf[0] = 'a';
  buf[1] = 'b';
  buf[2] = '\0';
 
  int i;
  for(i = 0; i< MAXBUF; ++i)
    {
      buf[i] = 'a' + i;
      
    }
 
  buf[MAXBUF] = '\0';  // does this cause problem at all?


  printf("buf is %s\n", buf);

}
