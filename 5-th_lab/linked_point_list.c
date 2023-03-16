#include "linked_point_list.h"
#include <stdio.h>
int is_empty(List list){
    return (list.size == 0);
}

int is_full(List list){
    return(list.size == NMAX);
}

void output(List list){
    for(int i = 0; i < list.size; i++){
        printf("%d ", list.index[i].data);
    }
    printf("\n");
}
void create(List * list){
    for(int i = 0; i < NMAX; i++){
        list->index[i].next = -1;
        list->index[i].data = '\0';
    }
}

void push(List * list, int index, int data){
    if(is_full(*list)){
        printf("List is full\n");
        return;
    }
    if(is_empty((*list))){
        list->index[list->head].data = data;
        list->index[list->head].next = -1;
        list->size++;
    }
    else if(list->index[index].data != '\0'){
        printf("Вы хотите добавить элемент перед(1) или после(0) заданного?\n");
        int n;
        scanf("%n");
    }
}
push_prev(List * list, int index, int data){

}
