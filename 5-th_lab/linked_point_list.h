#ifndef LINKED_POINT_LIST_H
#define LINKED_POINT_LIST_H
#define NMAX 10
typedef struct{
    int index;
    int data;
} Node;
typedef struct {
    int index[NMAX];
    int size;
    int head;
} List;
#endif