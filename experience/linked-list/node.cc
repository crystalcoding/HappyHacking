#include <iostream>
#include "node.h"

 node::node() {};
 node::node(int i)
 {
        data = i;
 }
 int node::get_data()
 {
     return data;
 }

node& node::get_next()
{
    return *next; //cause next is a pointer, and I want to return a reference
}
 void node::set_next(node& n)
 {
    next = &n;
 }

 node::~node() { std::cout << "node's destructor is called\n";}



