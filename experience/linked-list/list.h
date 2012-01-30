#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "node.h"

class list
{
    public:
        list();
        node* find_node_by_data(int n, node* current_pointer);
        void add_node_in_front(node &n);
        void remove_node_by_data(int i);
        bool is_empty();
        node* get_before(node* current_pointer);
        void print_list();
    private:
        int count;
        node* head;
        node* tail;
};


#endif // LIST_H_INCLUDED
