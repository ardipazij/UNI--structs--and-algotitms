#include "menu.h"
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
} 

void print_info(){
    printf("1. Случайное создание дерева.\n ");
   // printf("2. Поиск элемента в дереве \n");
    printf("3. Вывод дерева. \n");
    printf("4. Удаление дерева. \n");
    printf("0. Выход из программы. \n");
}

void add(Tree_node ** head){
    printf("Введите количество элментов, которое вы хотите добавить(от 1 до 50)\n");
    int n;
    if(get_number(&n) || n > 50 || n < 1){
        printf("Error input");
        return;
    }
    for (int i = 0; i < n; i ++){
        int f = rand() % 100;
        add_to_tree(head, f);
    }
}

void output(Tree_node * head){
    if(head == NULL){
        printf("Дерево пусто\n");
        return;
    }
    print_in_symmetric_order(head, 0);
}