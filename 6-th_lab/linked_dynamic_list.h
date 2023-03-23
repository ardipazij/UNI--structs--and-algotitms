#ifndef LINKED_DYNAMIC_LIST_H
#define LINKED_DYNAMIC_LIST_H
typedef struct List{
    int data;
    struct List * next_elem;
} List;
List * create();
int is_empty(List * list);
void delete_node(List ** list);
void destroy(List ** list);
void output(List * list);
void move_to_sublist(List ** list, List ** sublist, int number);
#endif