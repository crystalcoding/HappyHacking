#include <list>
#include "Student_info.h"
#include "grade.h"

using std::list;

list<Student_info>  extract_fails(list<Student_info>& s)
{
  list<Student_info> fail;
  
  //not good vector<Student_info>::iterator itr;
  list<Student_info>::iterator itr = s.begin();
  while( itr != s.end()){ //so '<' works too?
    if (fgrade(*itr)){
      fail.push_back(*itr);

      itr = s.erase(itr);  //s.erase(itr); not good
    }
    else{
      ++itr;
    }
  }

  return fail;
}
