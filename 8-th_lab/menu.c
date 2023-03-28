#include "menu.h"
#include "list_of_lists.h"
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
    printf("1. Вывести информацию o списке. \n");
    printf("2. Поиск заданного элемента.\n");
    printf("3.Добавление элемента в массив списков.\n");
    printf("4. Добавление элемента в список. \n");
    printf("5. Удаление элемента из списка списков.\n");
    printf("6. Удаление элемента из списка.\n");
    printf("0. Выход из программы.\n");
}