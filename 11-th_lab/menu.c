#include "menu.h"
#include "binary_tree_with_substack.h"
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
    printf("2. Вывод дерева. \n");
    printf("3. Удаление дерева. \n");
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
        print_in_simmetric_order_with_stack(head);
        break;
    case 3:
        print_in_inverse_symmetric_order(head, 0);
        break;
    default:
        printf("Неверный вводд \n");
        break;
    }
}