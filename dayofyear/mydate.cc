#include "mydate.h"
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

mydate::mydate():data(99)
{
}

void mydate::test()
{
  cout << "test function" << endl;
  cout << "private data variable:" << data << endl;
  
}

void mydate::getDay()
{
  time_t rawtime;
  struct tm* timeinfo;
  char buffer[80];
  
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, 80, "Day of the year is %j/365/%b%d", timeinfo);
  
  cout << buffer << endl;
}
