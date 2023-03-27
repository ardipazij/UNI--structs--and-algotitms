#include "doubly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
Node * init(){
    Node * tmp = calloc(1, sizeof(Node));
    tmp->next = tmp;
	tmp->prev = tmp;
    return(tmp);
}

int is_empty(Node * head){
    return(head->next == head);
}
void print_forward(Node* head)
{
	Node* tmp = head->next;
	while (tmp != head)
	{
		printf(" %d ", tmp->data);
		tmp = tmp->next;
	}
    printf("\n");
}
void print_reverse(Node* head)
{
	Node* tmp = head->prev;
	while (tmp != head)
	{
        printf(" %d ", tmp->data);
		tmp = tmp->prev;
	}
    printf("\n");
}
// 0 -- добавление после, 1 -- добавление до.
void add(Node ** head, int elem, int data, int answer){
    if(is_empty((*head)) && answer == 0){
        Node * current = calloc(1, sizeof(Node));
        current->data = data;
        current->next = (*head);
        current->prev = (*head);
        (*head)->prev = current;
        (*head)->next = current;
    }
    else if(is_empty((*head)) && answer == 1){
        printf("Add error\n");
    }
    else if(answer == 0){
        Node * current = (*head)->next;
        while(current != (*head) && current->data != elem){
            current = current->next;
        }
        if (current == (*head)){
            printf("Значение не найдено.\n");
            return;
        }
        Node * tmp = calloc(1, sizeof(Node));
        Node * next_current = current->next;
        tmp->data = data;
        tmp->next = next_current;
        tmp->prev = current;
        next_current->prev = tmp;
        current->next = tmp;
    }
    else if(answer == 1){
        Node * current = (*head)->next;
        while(current != (*head) && current->data != elem){
            current = current->next;
        }
        if (current == (*head)){
            printf("Значение не найдено.\n");
            return;
        }
        Node * tmp = calloc(1, sizeof(Node));
        Node * prev_current = current->prev;
        tmp->data = data;
        tmp->next = current;
        tmp->prev = prev_current;
        prev_current->next = tmp;
        current->prev = tmp;
    }
}
void remove_node(Node ** head, int data){
    if(is_empty((*head))){
        printf("Список пуст\n");
        return;
    }
    Node * current = (*head)->next;
    while(current != (*head) && current->data != data){
        current = current->next;
    }
    if(current == (*head)){
        printf("Элемент не найден.\n");
        return;
    }
    Node * next_current = current->next;
    Node * prev_current = current->prev;
    prev_current->next = next_current;
    next_current->prev = prev_current;
    delete_node(&current);
}
void delete_node(Node ** list){
    free(*list);
    //*tmp = NULL;
}
void find_elem_forward(Node * head, int data){
    if(is_empty(head)){
        printf("Список пуст\n");
        return;
    }
    Node * current = head->next;
    int index = 1;
    while(current != head && current->data != data){
        current = current->next;
        index++;
    }
    if(current == head){
        printf("Элемент не найден.\n");
        return;
    }
    printf ("Элемент %d найден на %d месте\n", current->data, index);
}
void find_elem_reverse(Node * head, int data){
    if(is_empty(head)){
        printf("Список пуст\n");
        return;
    }
    Node * current = head->prev;
    int index = 1;
    while(current != head && current->data != data){
        current = current->prev;
        index++;
    }
    if(current == head){
        printf("Элемент не найден.\n");
        return;
    }
    printf ("Элемент %d найден на %d месте\n", current->data, index);
}
void destroy(Node ** list){
    Node * current;
    (*list)->prev->next = NULL;
    while((*list) != NULL){
        current = (*list);
        (*list) = (*list)->next;
        free(current);
    }
}
int elem_not_exist(Node * head, int data){
    int len = 0;
    Node * cur = head->prev;
    while(cur!= head){
        cur = cur->prev;
        len++;
    }
    int index = 0;
    Node * current = head->prev;
    while(current != head && current->data != data){
        current = current->prev;
        index++;
    }
    return (index == len);
}