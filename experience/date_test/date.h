#include <iostream>
#include <string>

using std::string;
using std::istream;

class Date {
      private: 
               int y, m, d;
               string date_tag;
               
      public:
             Date();
             Date(istream& is);
             Date(const Date& d); //need const?
             Date& operator=(const Date& d); //need const?
             int getYear() const; //both interface and implementation needs 'const'
             int getMonth() const;
             int getDay() const;             
             void print_date_status() const;
             string get_date_tag() const;
             string& get_date_tag_return_reference() ;
             
             void set_date_tag(const string s);
             //void set_date_tag(string& s);
             
             string set_date_tag_levelone(const string s);
             string set_date_tag_leveltwo(const string s);
};
      
