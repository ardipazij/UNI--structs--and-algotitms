#ifndef LINKED_LIST_H
#define LINLED_LIST_h
const int NMAX = 10;
typedef struct {
    int data[NMAX];
    int size;
} Node;
int is_empty(Node list);
int is_full(Node list);
#endif