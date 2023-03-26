#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
typedef struct Node;
typedef struct{
    int data;
    Node * prev;
    Node * next;
}Node;
Node * init();
int is_empty(Node * head);
void print_forward(Node* head);
void print_reverse(Node* head);
int add(Node * head, int elem, int data, int answer);
void remove_node(Node * head, int data);
void find_elem_forward(Node * head, int data);
void find_elem_reverse(Node * head, int data);
#endif