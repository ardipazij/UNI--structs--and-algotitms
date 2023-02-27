#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#define SIZE 3
typedef struct queue{
    int data[SIZE];
    int back;
    int front;
} queue;
void init(queue * root);
int is_empty(queue root);
int is_full(queue root);
void add_element(queue * root, int n);
int remove_element(queue * root);
void output(queue root);
#endif