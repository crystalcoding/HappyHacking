#include "date.h"
#include <iostream>

using namespace std;

Date::Date():y(1),m(2),d(3), date_tag("default_date_tag")
{
}

Date::Date(istream& is)
{
 cout << "call 'Date(istream& is)' constructor" << endl;
 cout << "input y" << endl;
 is >> y;
 cout << "input m" << endl;
 is >> m;
 cout << "input d" << endl;
 is >> d;
}
Date::Date(const Date& md)
{
 y=md.y;
 m=md.m;
 d=md.d;
 date_tag = md.date_tag;
  
 cout << "copy constructor is called" << endl;
}

//Date::Date& operator=(const Date& rhs) wrong
Date& Date::operator=(const Date& rhs)
{
    //check self assignment
    if(this != &rhs) 
    {
       //1. delete resources
       //2. then assign 
       y = rhs.y;
       m = rhs.m;
       d = rhs.d;      
       date_tag = rhs.date_tag; 
    }
    cout << "copy assignment is called" << endl;    
    return *this;
}

int Date::getYear() const
{
    return y;
}

int Date::getMonth() const
{
    return m;
}

int Date::getDay() const
{
    return d;
}

void Date::print_date_status() const
{
     cout << "year:" << y <<" month:" << m << " day:" << d << " date_tag:"
          << date_tag << endl;
}

string Date::get_date_tag() const
{
       return date_tag;
}

string& Date::get_date_tag_return_reference() 
{
       return date_tag;
}

void Date::set_date_tag(string s)
{
     date_tag = s;
}

/*
void Date:set_date_tag(string& s)
{
     date_tag = s;
}
*/

string Date::set_date_tag_levelone(const string s)
{
       cout << "set_date_tag_levelone() is called" << endl;
       string ss = s;
       cout << "now passing paramerter is \"" << ss <<"\"" << endl;
       
       return set_date_tag_leveltwo(ss);
}

string Date::set_date_tag_leveltwo(const string s)
{
       cout << "set_date_tag_leveltwo() is called" << endl;
       cout << "now passing parameter is \"" << s << "\"" << endl;
       return s;
}

