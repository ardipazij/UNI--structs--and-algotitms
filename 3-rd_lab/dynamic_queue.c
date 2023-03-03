#include <stdio.h>
#include "dynamic_queue.h"
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int is_empty(DblLinkedList * list){
    return ((list)->head || (list)->tail);
}
DblLinkedList * create_list(){
    DblLinkedList * list = calloc(1, sizeof(struct DblLinkedList));
    list->head = list->tail = NULL;
    return list;
}

void pushBack(DblLinkedList ** list, char statement[4]) {
    queue_d * temp = calloc(1, sizeof(struct queue_d));
    if (temp == NULL) {
        printw("Memmory error push\n");
        exit(1);
    }
    strcpy(temp->data, statement);
    temp->next_elem = NULL;
    temp->prev_elem = (*list)->tail;
    if ((*list)->tail) {
         (*list)->tail->next_elem = temp;
     }
     (*list)->tail = temp;
 
    if ((*list)->head == NULL) {
        (*list)->head = temp;
    }
}

char* popFront(DblLinkedList **list) {
    queue_d *prev;
    char *tmp = calloc(4, sizeof(char));
    if (tmp == NULL) {
        printw("Memmory error pop\n");
        exit(1);
    }
 
    prev = (*list)->head;
    (*list)->head = (*list)->head->next_elem;
    if ((*list)->head) {
        (*list)->head->prev_elem = NULL;
    }
    if (prev == (*list)->tail) {
        (*list)->tail = NULL;
    }
    strcpy(tmp, prev->data);
    free(prev);
    return tmp;
}


void destroy(DblLinkedList **list) {
    queue_d * temp = (*list)->head;
    queue_d * next = NULL;
    while (temp) {
        next = temp->next_elem;
        free(temp);
        temp = next;
    }
    free(*list);
    (*list) = NULL;
}
void output(DblLinkedList *list){
    queue_d * temp = list->head;
    while (temp) {
        printw("%s ", temp->data);
        temp = temp->next_elem;
    }
    printw("\n");
}