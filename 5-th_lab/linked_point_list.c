#include "linked_point_list.h"
#include <stdio.h>
#include "menu.h"
int is_empty(List list){
    return (list.size == 0);
}

int is_full(List list){
    return(list.size == NMAX);
}

void output(List list){
    for(int i = list.array[0].next ; i != 0; i = list.array[i].next){
        printf("%d ", list.array[i].data);
    }
    printf("\n");
}
void create(List * list){
    list->array[0].data = 0;
    list->array[0].next = 0;
    for(int i = 1; i <= NMAX; i++){
        list->array[i].next = -1;
        list->array[i].data = '\0';
    }
}

void push(List * list){
    if(is_full(*list)){
        printf("List is full\n");
        return;
    }
    if(is_empty((*list))){
        printf("Введите значение элемента:\n");
        int n;
        if(get_number(&n)){
            printf("Неккоректный ввод\n");
            return;
        }
        list->array[1].data = n;
        list->array[1].next = 0;
        list->array[0].next = 1;
        list->size++;
    }
    else{
        printf("Вы хотите добавить элемент перед(1) или после(0) заданного?\n");
        int n;
        if(get_number(&n)){
            printf("Неккоректный ввод\n");
            return;
        }
        if(n==0){
            int elem;
            if(get_number(&elem)){
                printf("Неккоректный ввод\n");
                return;
            }
            int index_item = find_elem(*list,elem);
            if(index_item == -1){
                printf("Элемента не существует\n");
                return;
            }
            int new_item;
            if(get_number(&new_item)){
                printf("Неккоректный ввод\n");
                return;
            }
            int free_index;
            for (free_index = 1; free_index <= list->size; ++free_index)
				if (list->array[free_index].next == -1) break;
            (*list).array[free_index].next = (*list).array[index_item].next;
			(*list).array[index_item].next = free_index;
			(*list).array[free_index].data = new_item;
            list->size++;
        } else if(n == 1){

        }
    }
}
int find_elem(List list, int elem){
    for(int i = list.array[0].next; i != 0; i = list.array[i].next ){
        if(elem == list.array[i].data){
            return i;
        }
    }
    return -1;
}