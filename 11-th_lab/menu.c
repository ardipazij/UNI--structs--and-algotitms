#include "menu.h"
#include "binary_tree.h"
#include <stdio.h>
int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
} 

void print_info(){
    printf("1. Добавление элемента в дерево.\n ");
    printf("2. Поиск элемента в дереве \n");
    printf("3. Вывод дерева. \n");
    printf("4. Удаление дерева. \n");
    printf("0. Выход из программы. \n");
}

void output(Tree_node * head){
    if(head == NULL){
        printf("Дерево пусто \n");
        return;
    }
    printf("Как вы хотите вывести дерево?\n");
    printf("1. B прямом порядке\n");
    printf("2. B симметричном порядке.\n");
    printf("3. B обратно-симметричном порядке\n");
    int n;
    if(get_number(&n)){
        printf("Неккоретный ввод");
    }
    switch (n)
    {
    case 1:
        print_in_direct_order(head, 0);
        break;
    case 2:
        print_in_symmetric_order(head, 0);
        break;
    case 3:
        print_in_inverse_symmetric_order(head, 0);
        break;
    default:
        printf("Неверный вводд \n");
        break;
    }
}

void find(Tree_node * head){
    printf("Введите значение для поиска\n");
    int value;
    if(get_number(&value)){
        printf("Неверный ввод. \n");
        return;
    }
    Tree_node * result = NULL;
    int status = 0;
    find_in_tree(head, value, &result, &status);
    if(result == NULL){
        printf("Элемент не найден. \n");
    }
    else{
        printf("Элемент найден\n");
    }
}
void add(Tree_node ** head){
    if((*head) == NULL){
        printf("Введите значение, которое вы хотите добавить в корень дерева: \n");
        int value;
        if(get_number(&value)){
            printf("Неверный ввод \n");
            return;
        }
        (*head) = create(value);
        return;
    }
    printf("Введите значение вершины, в потомка которой будет добввлено новое значение: \n");
    int searching;
    if(get_number(&searching)){
        printf("Неверный ввод \n");
        return;
    }
    Tree_node * result = NULL;
    int status = 0;
    find_in_tree((*head), searching, &result, &status);
    if(result == NULL){
        printf("Элемент не найден \n");
        return;
    }
    printf("Введите значение новой вершины\n");
    int value;
    if(get_number(&value)){
        printf("Неверный ввод \n");
       return;
    }
    add_to_node(&result, value);
}