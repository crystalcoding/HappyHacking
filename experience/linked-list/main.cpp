#include <iostream>
#include "node.h"
#include "list.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    node* n = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    node* n4_1 = new node(4);

   n->get_data();

   //list l(); THIS IS NOT RIGHT, it call the "function" in a list, not a construction!
   list l;

   l.add_node_in_front(*n);
   l.add_node_in_front(*n2);
   l.add_node_in_front(*n3);
   l.add_node_in_front(*n4);
   l.add_node_in_front(*n4_1);
   l.remove_node_by_data(3);
   l.print_list();

   int tmp;
   cin >> tmp;
    return 0;
}
