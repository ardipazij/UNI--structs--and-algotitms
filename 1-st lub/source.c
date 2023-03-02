#include "dynamic_stack.h"
#include <stdlib.h>
#include <stdio.h>
stack * create(){
    stack *new_stack;
    new_stack = calloc(1, sizeof(struct stack));
    if( new_stack == NULL){
        printf("Out of memory\n");
        exit(1);
    }
    new_stack->next_stack = NULL;
    // printf("Создан новый элемент стека\n");
    return new_stack;
}
stack * push(stack ** prev, int data ){
    stack * new_stack = create();
    new_stack->data = data;
    new_stack->next_stack = *prev;
    *prev = new_stack;
    // printf("В новый элемент добавлено значение\n");
    return (*prev);
}
int pop(stack **prev){
    stack * tmp = *prev;
    *prev = (*prev)->next_stack;
    int data = (tmp)->data;
    delete_stack(&tmp);
    printf("Из стека удалено значение\n");
    return data;
}
int is_empty(stack * tmp){
    int c_flag;
    if(tmp->next_stack == NULL){
        c_flag = 1;
    } else{
        c_flag = 0;
    }
    return c_flag;
}
void delete_stack(stack ** tmp){
    free(*tmp);
    //*tmp = NULL;
}
void output(stack *tmp){
    while(tmp->next_stack != NULL){
        printf("%d \n", tmp->data);
        tmp = tmp->next_stack;
    }
    printf("Элементов для вывода больше нет\n");
}
void destroy(stack ** root){
    stack * tmp = *root;
    while(tmp != NULL && (*root) != NULL){
        *root = (*root)->next_stack;
        delete_stack(&tmp);
        tmp = (*root);
    }
}
void push_random(stack ** tmp, int n){
    for(int i = 0; i < n;i++){
        int data = rand() % 100;
        push(tmp, data);
    }
}
void move(stack ** head, stack ** subhead){
    stack * temp;
    if((*head)->next_stack != NULL){
        temp = (*head);
        (*head) = (*head)->next_stack;
        temp->next_stack = (*subhead);
        (*subhead) = temp; 
        printf("Элемент %d перемещён во вспомогательный стек\n", temp->data);
    }
    else{
        printf("Запрашиваемый стек пуст\n");
    }
}