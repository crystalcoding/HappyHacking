#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class node{
    public:
        node();
        node(int i);
        int get_data();
        node& get_next();
        void set_next(node&);
        ~node();

    private:
        int data;
        node* next;
};

#endif // NODE_H_INCLUDED

