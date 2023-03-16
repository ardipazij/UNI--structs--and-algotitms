#include "linked_point_list.h"
#include <stdio.h>
int is_empty(List list){
    return (list.size == 0);
}

int is_full(List list){
    return(list.size == NMAX);
}

void output(List list){
    for(int i = list.array[0].next ; i != -1; i = list.array[i].next){
        printf("%d ", list.array[i].data);
    }
    printf("\n");
}
void create(List * list){
    list->array[0].data = 0;
    list->array[0].next = 0;
    for(int i = 1; i < NMAX+1; i++){
        list->array[i].next = -1;
        list->array[i].data = '\0';
    }
}

void push(List * list, int index, int data){
    if(is_full(*list)){
        printf("List is full\n");
        return;
    }
    if(is_empty((*list))){
        list->array[1].data = data;
        list->array[1].next = -1;
        list->array[0].next = 1;
        list->size++;
    }
    else if(list->array[index].data != '\0'){
        printf("Вы хотите добавить элемент перед(1) или после(0) заданного?\n");
        int n;
        scanf("%n");
        if(n==0){

        } else if(n == 1){

        }
    }
}
int find_elem(List list, int elem){
    for(int i = list.array[0].next; i != -1; i = list.array[i].next ){
        if(elem == list.array[i].data){
            return i;
        }
    }
    return -1;
}