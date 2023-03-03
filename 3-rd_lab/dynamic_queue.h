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
int is_empty(DblLinkedList *list);
DblLinkedList * create_list();
void pushBack(DblLinkedList ** list, char statement[4]);
char * popFront(DblLinkedList **list);
void destroy(DblLinkedList **list);
void output(DblLinkedList *list);
#endif