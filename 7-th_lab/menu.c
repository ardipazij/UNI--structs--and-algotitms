#include "menu.h"
#include "doubly_linked_list.h"
#include <stdio.h>
int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
}
void output(Node * head){
    if(is_empty(head)){
        printf("Список пуст.\n");
        return;
    }
    printf("Вывод списка в прямом порядке(0) или в обратном(1)?\n");
    int n;
    if(get_number(&n)){
        printf("Input error.\n");
        return;
    }
    switch (n)
    {
    case 0:
        print_forward(head);
        break;
    case 1:
        print_reverse(head);
        break;
    default:
        printf("Number error");
        break;
    }
}
void find(Node * head){
    printf("Поиск элемента в прямом порядке(0) или в обратном(1)?\n");
    int n;
    if(get_number(&n)){
        printf("Input error.\n");
        return;
    }
    printf("Введите элемент:\n");
    int data;
    if(get_number(&data)){
        printf("Input error.\n");
        return;
    }
    switch (n)
    {
    case 0:
        find_elem_forward(head, data);
        break;
    case 1:
        find_elem_reverse(head, data);
        break;
    default:
        printf("Number error");
        break;
    }
}

void print_list(){
    printf("1. Вывести информацию o списке\n");
    printf("2. Выполнить поиск элемента\n");
    printf("3. Добавление элемента\n");
    printf("4. Удаление элемента\n");
    printf("Выход из программы\n");
}

void add_elem(Node ** head){
    printf("Введите элемент, который хотите добавить:\n");
    int elem;
    if(get_number(&elem)){
        printf("Ошибка ввода");
        return;
    }
    printf("Введите элемент, до или после которого вы хотите вставить элемент:\n");
    int data;
    if(get_number(&data)){
        printf("Ошибка ввода");
        return;
    }
    if(elem_not_exist((* head),data) && !is_empty(*head)){
        printf("элемент не существует\n");
        return;
    }
    printf("Вы хотите вставить элемент до(1) или после(0)?");
    int answer;
    if(get_number(&answer)){
        printf("Ошибка ввода");
        return;
    }
    add(head,data,elem,answer);
}
void remove_elem(Node ** head){
    int data;
    if(get_number(&data)){
        printf("Ошибка ввода");
        return;
    }
    remove_node(head, data);
}