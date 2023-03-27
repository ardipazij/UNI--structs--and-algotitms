#include "list_of_lists.h"
#include <stdio.h>
#include <stdlib.h>

int is_empty_list(Node_of_lists * list){
    return(list->next == NULL);
}
int is_empty_node(Node * list){
    return (list->next == NULL);
}
Node * create_node(){
    Node *new_stack;
    new_stack = calloc(1, sizeof(struct Node));
    if( new_stack == NULL){
        printf("Out of memory\n");
        exit(1);
    }
    new_stack->next = NULL;
    new_stack->data = '\0';
    // printf("Создан новый элемент\n");
    return new_stack;
}
Node_of_lists * create_node_of_lists(){
    Node_of_lists *new_stack;
    new_stack = calloc(1, sizeof(struct Node));
    if( new_stack == NULL){
        printf("Out of memory\n");
        exit(1);
    }
    new_stack->next = NULL;
    // printf("Создан новый элемент\n");
    return new_stack;
}
void add_to_node (Node ** list, int answer, int number, int number_to_add){
    if(is_empty_node(*list) && answer == 0 ){
        printf("B пустой список нельзя добавить элемент до заголовка.\n");
        return;
    }
    else if(is_empty_node(*list) && answer == 1 ){
        Node * tmp = create_node();
        tmp->data  = number_to_add;
        (*list)->next = tmp;
        return;
    }
    else if(answer == 1){
        Node * tmp = *list;
        while((tmp) != NULL && tmp->data != number){
            tmp = tmp->next;
        }
        if(tmp == NULL){
            printf("Элемент не найден. \n");
            return;
        }
        Node* new_elem = create_node();
		new_elem->next = tmp->next;
		new_elem->data = number_to_add;
		tmp->next = new_elem;

    }
    else if(answer == 0){
        Node * tmp = *list;
        Node * prev;
        while(tmp != NULL && tmp->data != number){
            prev = tmp;
            tmp = tmp->next;
        }
        if(list == NULL){
            printf("Элемент не найден. \n");
            return;
        }
        Node * new_elem = create_node();
		new_elem->next = tmp;
		new_elem->data = number_to_add;
		prev->next = new_elem;

    } else{
        printf("Input error \n");
    }
}
// ответ 0 -- добавление до, ответ 1 -- добавление после
void add_to_node_list (Node_of_lists ** list, int answer, int index, int new_index, Node * list_to_add){
    if(is_empty(*list) && answer == 0 ){
        printf("B пустой список нельзя добавить элемент до заголовка.\n");
        return;
    }
    else if(is_empty(*list) && answer == 1 ){
        Node_of_lists * tmp = create_node_of_lists();
        tmp->index  = new_index;
        tmp->data = list_to_add;
        tmp->next = NULL;
        (*list)->next = tmp;
        return;
    }
    else if(answer == 1){
        Node_of_lists * tmp = *list;
        while((tmp) != NULL && tmp->index != index){
            tmp = tmp->next;
        }
        if(tmp == NULL){
            printf("Индекс не найден. \n");
            return;
        }
        Node_of_lists * new_elem = create_node_of_lists();
		new_elem->next = tmp->next;
		new_elem->data = list_to_add;
        new_elem->index = new_index;
		tmp->next = new_elem;

    }
    else if(answer == 0){
        Node * tmp = *list;
        Node * prev;
        while(tmp != NULL && tmp->data != number){
            prev = tmp;
            tmp = tmp->next;
        }
        if(list == NULL){
            printf("Элемент не найден. \n");
            return;
        }
        Node * new_elem = create_node();
		new_elem->next = tmp;
		new_elem->data = number_to_add;
		prev->next = new_elem;

    } else{
        printf("Input error \n");
    }
}

