#ifndef LINKED_LIST_H
#define LINLED_LIST_h
#define NMAX 10
typedef struct {
    int data[NMAX];
    int size;
} Node;
int is_empty(Node list);
int is_full(Node list);
void push(Node * list);
int get_number(int * n);
void output(Node list);
#endif