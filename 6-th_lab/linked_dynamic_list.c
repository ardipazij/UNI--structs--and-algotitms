#include "linked_dynamic_list.h"
#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
List * create(){
    List *new_stack;
    new_stack = calloc(1, sizeof(struct List));
    if( new_stack == NULL){
        printf("Out of memory\n");
        exit(1);
    }
    new_stack->next_elem = NULL;
    // printf("Создан новый элемент стека\n");
    return new_stack;
}
int is_empty(List * list){
    int flag;
    if (list->next_elem == NULL){
        flag = 1;
    } else {
        flag = 0;
    }
    return flag;
}
void delete_node(List ** list){
    free(*list);
    //*tmp = NULL;
}
void destroy(List ** list){
    List * tmp = *list;
    while(tmp != NULL && (*list) != NULL){
        *list = (*list)->next_elem;
        delete_node(&tmp);
        tmp = (*list);
    }
}