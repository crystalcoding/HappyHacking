#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

class meimei {
public:
  //Does your class need a constructor?
  //Does your class have a constructor without arguments?
  meimei();

  //Does every constructor initialize every data member?
  meimei(string name, int cute_level, char* picture_code); //implement here?

  //Does your class need a copy constructor?
  //Constant argument in copy constructor?
  //Constant reference is required?
  meimei(const meimei&);
 
  //Does your class need an assignment operator?
  //Check assigning to itself?
  //Constant argument in assignment operator?
  //Constant reference is required?
  meimei& operator=(const meimei&);

  //Does your class need to define the relational operators?
  bool operator==(const meimei&);

  //Did you remember to declare your member functions const apropriately?
  string get_name() const;
  int get_cute_level() const;
  char* get_picture_code() const;

  //Does the class need a destructor?
  //Does the class need a virtual destructor?
  virtual ~meimei();
  
private:
  //are your data members private?
  string name;
  int cute_level;
  char* picture_code;

};

meimei::meimei(): name("no name"),cute_level(0),
		  picture_code(0) //or ""?
{  
}
//same name?
meimei::meimei(string n, int level, char* pic_code):
  name(n), cute_level(level), 
  picture_code(strcpy(new char[strlen(pic_code)+1], pic_code ? pic_code:""))
{
}

meimei::meimei(const meimei& m)
{
  name = m.get_name();//if get_name() is not const, 
                      //the argument const meimei won't happy 
  cute_level = m.get_cute_level();
  
  //do I have to check null here?
  //because picture_code should always be null here right?
  picture_code = new char[strlen(m.get_picture_code())+1];
  strcpy(picture_code, m.get_picture_code());
  //wrong picture_code = m.get_picture_code(); //be careful here
}

//&meimei or meimei&?
meimei& meimei::operator=(const meimei& m)
{
  if ( &m != this )
    {
      name = m.get_name(); //std string's '='?
      cute_level = m.get_cute_level();

      delete[] picture_code; //delete original
      picture_code = new char[strlen(m.get_picture_code())+1];
      strcpy(picture_code, m.get_picture_code()); //usenew
      //picture_code = m.get_picture_code(); blah...
    }

  return *this;
}

bool meimei::operator==(const meimei& m)
{
  return name == m.get_name();
}

string meimei::get_name() const
{
  return name;
}

int meimei::get_cute_level() const
{
  return cute_level;
}

char* meimei::get_picture_code() const
{
  return picture_code;
}

//repeat virtual keyword here? NO.
meimei::~meimei()
{
  delete[] picture_code;
}

void print_meimei(const meimei& m)
{
  cout << m.get_name() << endl;
  cout << m.get_cute_level() << endl;
  cout << m.get_picture_code() << endl;
  cout << endl;
  
}
int main()
{
  char* emily_c = new char[3];
  emily_c[0] = 'a';
  emily_c[1] = 'b';
  emily_c[2] = '\0';
  meimei emily("Emily", 1, emily_c);

  print_meimei(emily);

  meimei emily2 = emily;

  print_meimei(emily2);
  print_meimei(emily);

  char* emily_c2 = new char[4];
  emily_c2[0] = 'c';
  emily_c2[1] = 'd';
  emily_c2[2] = 'e';
  emily_c2[3] = '\0';
  meimei emily3("Emily3", 2, emily_c2);
  
  print_meimei(emily3);

  emily3 = emily2;
  print_meimei(emily3);
  print_meimei(emily2);  
}

