/*
1. Информация о состоянии очереди
2. Добавление элемента в очередь
3. Удаление элемента из очереди
0. Завершить работу программы*/
#include <stdio.h>
#include "menu.h"

void status(queue root){
    if(is_empty(root)){
        printf("Очередь пуста\n");
        return;
    }
    else{
        output(root);
        printf("Элементов для вывода больше нет \n");
    }
}
int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
}
void menu_add_element(queue * root){
    if(is_full(* root)){
        printf("Очередь заполнена\n");
        return;
    }
    int n;
    if(get_number(&n)){
        printf("Неверный ввод\n");
        return;
    }
    add_element(root, n);
    printf("Элемент добавлен\n");
}
void menu_remove_elements(queue * root){
    if(is_empty(* root)){
        printf("Очередь пуста\n");
        return;
    }
    printf("%d\n", remove_element(root));
    printf("Элемент удален\n");
}