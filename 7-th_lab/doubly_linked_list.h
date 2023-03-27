#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
typedef struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
}Node;
Node * init();
int is_empty(Node * head);
void print_forward(Node* head);
void print_reverse(Node* head);
void add(Node ** head, int elem, int data, int answer);
void remove_node(Node ** head, int data);
void find_elem_forward(Node * head, int data);
void find_elem_reverse(Node * head, int data);
void delete_node(Node ** list);
int elem_not_exist(Node * head, int data);
#endif