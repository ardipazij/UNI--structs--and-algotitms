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
    printf("1. Cоздание дерева/добавление элемента в дерево.\n ");
    printf("2. Поиск элемента в дереве \n");
    printf("3. Вывод дерева. \n");
    printf("4. Удаление вершины\n");
    printf("5. Удаление дерева. \n");
    printf("0. Выход из программы. \n");
}

void add(Tree_node ** head){
    // if(*head != NULL){
    //     printf("Для создания нового удалите старое дерево\n");
    //     return;
    // }
    printf("Пользовательский ввод(0) или случайное заполнение(1)?(при случайном заполнении старое дерево будет удалено)\n");
    int flag;
    if(get_number(&flag)){
        printf("Неверный ввод\n");
        return;
    }
    if(flag == 1){
        destroy(head);
        printf("Введите количество элментов, которое вы хотите добавить(от 1 до 50)\n");
        int n;
        if(get_number(&n) || n > 50 || n < 1){
           printf("Error input\n");
            return;
         }
         for (int i = 0; i < n; i ++){
            int key_rand = rand() % 100;
            add_to_tree(head, key_rand);
         }
    }
    else if(flag == 0){
        printf("Введите значение ключа\n");
        int key;
        if(get_number(&key)){
            printf("Неверный ввод\n");
            return;
        }
        add_to_tree(head, key);
    }
}

void output(Tree_node * head){
    if(head == NULL){
        printf("Дерево пусто\n");
        return;
    }
    print_in_symmetric_order(head, 0);
}

void find(Tree_node * root){
    if(root == NULL){
        printf("Дерево пусто.\n");
        return;
    }
    else{
        int data;
        printf("Введите значение ключа для поиска\n");
        if(get_number(&data)){
            printf("Ошибка ввода \n");
            return;
        }
        Tree_node * current = find_elem(root, data);
        if(current != NULL){
            printf("Элемент с ключом %d найден. Количество появлений -- %d\n", current->key, current->count );
            return;
        }
        else{
            printf("Элемент не найден\n");
            return;
        }
    }
}

void delete_node(Tree_node ** head){
    printf("Введите ключ вершины, которую вы хотите удалить\n");
    int data;
    if(get_number(&data)){
        printf("Ошибка ввода\n");
        return;
    }
    remove_elem(head, data);
}

void destroy_tree(Tree_node **  head){
    destroy(head);
   // *head = NULL;
}