
#include <iostream>
#include "list.h"
#include "node.h"

using namespace std;


list::list()
{
    head = tail = 0;
}

node* list::find_node_by_data(int i, node* current_pointer)
{
    while(current_pointer != tail) //use while not if !
    {
        if(current_pointer->get_data() == i)
        {
            //return current_pointer; WRPMG???
            return current_pointer;
        }

        current_pointer = &(current_pointer->get_next());
    }

    return tail;
}

void list::add_node_in_front(node& n)
{
    if (head == tail)
    {
        head = &n;
        //head->set_next(tail); tail is a pointer, but I implement set_next take reference
        head->set_next(*tail);
        ++count;

    }
    else
    {
        node* tmp;
        tmp = head;

        head = &n; //or *head = node? =p
        n.set_next(*tmp); //set_next() take a node reference,
                          //  not a pointer, so NOT "tmp" (pointer),
                          //NOR "&tmp" pointer of pointer

        ++count;
    }

}

void list::remove_node_by_data(int i)
{
    node* current_pointer = head;
    while( !is_empty() && current_pointer != tail)
    {
        //start from head to find the target
        current_pointer = find_node_by_data(i, current_pointer);
        //delete current_pointer;
        //delete current_pointer;
        //start to remove node from the list
        //1. remove head
        if(current_pointer == head)
        {
            //only one node
            if( &(head->get_next())  == tail)
            {
                delete head;
                head = tail = 0;
                --count;
                current_pointer = tail;
            }
            else  //more than one node
            {
                node* tmp = &(head->get_next());
                delete head;
                head = tmp;
                --count;
                current_pointer = head;
            }
        }

        //2. remove at the end
        else if ( current_pointer != tail && &(current_pointer->get_next()) == tail) //need to check if the current_pointer is tail already, or seg fault!
        {
            node* before_current_pointer = get_before(current_pointer);
            delete current_pointer;
            before_current_pointer->set_next(*tail);
            --count;
            current_pointer = tail;
        }

        //3. remove at the middle
        else if(current_pointer != tail)
        {
            node* before_current_pointer = get_before(current_pointer);
            before_current_pointer->set_next(current_pointer->get_next());
            --count;
            delete current_pointer;
            //!!!! frogot to set the current_ponter back!!
            current_pointer = 0; //!good habit!!!
            current_pointer = &(before_current_pointer->get_next());

        }
        else
        {
            //do nothing because current_pointer must be tail,  target is not found, nothing to remove
        }
    }

}

bool list::is_empty()
{
    return head == tail;
}

node* list::get_before(node* current_pointer)
{
        node* before = head;
        while( (&(before->get_next()) != tail) && (&(before->get_next()) != current_pointer) )
            before = &(before->get_next());

        return before;
}

void list::print_list()
{
    node* current_pointer = head;
    while ( current_pointer != tail)
    {
        cout << current_pointer->get_data();
        //current_pointer = current_pointer.get_next(); current_pointer is of non-class type, so use pointer to do it
        current_pointer = &(current_pointer->get_next());  //or (*current_pinter).get_next() ?? =p since * is "less" than  .
    }
}
