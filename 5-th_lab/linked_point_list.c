#include "linked_point_list.h"

int is_empty(List list){
    return (list.size == 0);
}

int is_full(List list){
    return(list.size == NMAX);
}

void output(List list){
    for(int i = 0; i < list.size; i++){

    }
}
void create(List * list){
    for(int i = i; i < NMAX; i++){
        list->index[i].next = -1;
        list->index[i].data = '\0';
    }
}

void push(List * list, int index, int data){
    if(is_empty((*list))){
        list->index[list->head].data = data;
        list->index[list->head].next = -1;
        list->size++;
    }
    else if(list->index[index].data != '\0'){
        printf("Вы хотите добавить элемент перед(1) или после(0) заданного?\n");
        int n;
        scanf("%n")
    }
}
push_prev(List * list, int index, int data){

}
