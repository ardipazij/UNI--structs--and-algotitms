#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H
typedef struct queue_d{
    char data[3];
    struct queue_d * next_elem;
    struct queue_d * prev_elem;
    
} queue_d;
typedef struct DblLinkedList {
    size_t size;
    queue_d *head;
    queue_d *tail;
} DblLinkedList;
int is_empty(queue_d *head);
void pushBack(DblLinkedList * list, char statement[3]);
char * popFront(DblLinkedList *list);
void output(queue_d *head);
#endif