#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
typedef struct{
    int data;
    struct List * next;
    struct List * prev;
} List;
List * create();
#endif
