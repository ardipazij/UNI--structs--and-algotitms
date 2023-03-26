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
    if(get_number){
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
    if(get_number){
        printf("Input error.\n");
        return;
    }
    switch (n)
    {
    case 0:
        find_forward(head);
        break;
    case 1:
        find_reverse(head);
        break;
    default:
        printf("Number error");
        break;
    }
}