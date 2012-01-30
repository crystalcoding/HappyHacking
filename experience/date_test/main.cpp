#include <cstdlib>
#include <iostream>
#include "date.h"

using namespace std;

int main(int argc, char *argv[])
{
    Date myD;
    cout << myD.getYear() << myD.getMonth() << myD.getDay() << endl;
    
    Date myDD = myD; //copy constructor is called
    Date myDDD(myD); //copy constructor is called
    myDD.print_date_status();
    myDDD.print_date_status();
    
    Date myDDDD;
    myDDDD = myD;    //copy assignment is called
    myDDDD.print_date_status();
    myDDDD.set_date_tag("lala");
    cout << myDDDD.get_date_tag() << endl;  //print lala
    cout << myDDDD.get_date_tag_return_reference() << endl; //print lala
    
    myDDDD.set_date_tag(myDDDD.set_date_tag_levelone("seting my tag use two level"));
    myDDDD.print_date_status();
    
    //interactive constructor using std::cin (std::istream&)
    Date date_cin_constructed(cin);
    date_cin_constructed.print_date_status();
    system("PAUSE");
    return EXIT_SUCCESS;
}
