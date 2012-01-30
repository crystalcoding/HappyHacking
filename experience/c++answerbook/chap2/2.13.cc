#include <iostream>
#include <vector>
#include <string>

using namespace std;

  struct md
  {
    string month;
    int day;
  };

int main()
{
  vector<string> month(12);
  month[0] = "January";
  month[1] = "Feburary";
  month[2] = "March";
  month[3] = "April";
  month[4] = "May";
  month[5] = "June";
  month[6] = "July";
  month[7] = "August";
  month[8] = "September";
  month[9] = "October";
  month[10] = "November";
  month[11] = "December";

  vector<int> day(12);
  day[0] = 31;
  day[1] = 28;
  day[2] = 31;
  day[3] = 30;
  day[4] = 31;
  day[5] = 30;
  day[6] = 31;
  day[7] = 31;
  day[8] = 30;
  day[9] = 31;
  day[10] = 30;
  day[11] = 31;

  for (int i=0; i < 12; ++i)
    cout << "Month:" << month[i] << " day:" << day[i] << endl;


  //have to move the struct out??? why???
  vector<md> mds(12); //what's wrong?
  
  for(int i=0; i<12; ++i)
    {
      mds[i].month = month[i];
      mds[i].day = day[i];

      cout << "Month:" << mds[i].month << " day:" << mds[i].day << endl;
    }
}
