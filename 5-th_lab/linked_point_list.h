#ifndef LINKED_POINT_LIST_H
#define LINKED_POINT_LIST_H
#define NMAX 10
typedef struct{
    int next;
    int data;
} Node;
typedef struct {
    Node array[NMAX+1];
    int size;
    int head;
} List;
int is_empty(List list);
int is_full(List list);
void output(List list);
void create(List *list);
int find_elem(List list, int elem);
void push(List * list);
#endif