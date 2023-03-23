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
void output(List * list){
    if(is_empty(list)){
        printf("List is empty\n");
        return;
    }
    while(list->next_elem != NULL){
        printf("%d ", list->data);
        list = list->next_elem;
    }
    printf("\n");
}// ответ 0 -- добавление до, ответ 1 -- добавление после
void add (List ** list, int answer, int number, int number_to_add){
    if(is_empty(*list) && answer == 0 ){
        printf("B пустой список нельзя добавить элемент до заголовка.\n");
        return;
    }
    else if(answer == 1){
        List * tmp = *list;
        while((tmp) != NULL){
            tmp = tmp->next_elem;
            if(tmp->data == number){
                break;
            }
        }
        if(tmp == NULL){
            printf("Элемент не найден. \n");
            return;
        }
        List* new_elem = create();
		new_elem->next_elem = tmp->next_elem;
		new_elem->data = number_to_add;
		tmp->next_elem = new_elem;

    }
    else if(answer == 0){
        List * tmp = *list;
        List * prev;
        while(tmp != NULL){
            prev = tmp;
            tmp = tmp->next_elem;
            if(tmp->data == number){
                break;
            }
        }
        if(list == NULL){
            printf("Элемент не найден. \n");
            return;
        }
        List* new_elem = create();
		new_elem->next_elem = tmp;
		new_elem->data = number_to_add;
		prev->next_elem = new_elem;

    } else{
        printf("Input error \n");
    }
}

void move_to_sublist(List ** list, List ** sublist, int number){
    	List * cur = (*list)->next_elem;
		List* prev = *list;
        while(cur != NULL){
            if(cur->data == number)
                break;

            prev = cur;
            cur = cur->next_elem;
        }
        if(cur == NULL){
            printf("Элемент не найден \n");
            return;
        }
		List * tmp = cur;
		prev->next_elem = cur->next_elem;
		tmp->next_elem = (*sublist)->next_elem;
		(*sublist)->next_elem = tmp;
}