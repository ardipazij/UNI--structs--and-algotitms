#include "menu.h"
#include "linked_dynamic_list.h"
#include "stdio.h"
int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
}
void print_info(){
    printf("1. Вывести на экран информацию o списке\n");
    printf("2. Вывести на экран информацию o вспомогательном списке\n");
    printf("3. Добавить элемент в список\n");
    printf("4. Удалить элемент из списка\n");
    printf("0. Выйти из программы\n");
}
void status_sublist(List * list){
    printf("Состояние вспомогательного списка\n");
    output(list);
}
void add_to_list(List ** list){
    printf("Вы хотите внести новое значение до элемента(0), или после(1)? \n");
    int answer;
    if(get_number(&answer)){
        printf("Неккоректный ввод");
        return;
    }
    printf("Введите значение элемента. Если список пуст -- введите любое целое число.\n");
    int number;
     if(get_number(&number)){
        printf("Неккоректный ввод");
        return;
    }
    printf("Введите добавляемое значение\n");
    int number_to_add;
     if(get_number(&number_to_add)){
        printf("Неккоректный ввод");
        return;
    }
    add(list,answer, number, number_to_add);
}

void remove_elem(List ** list, List ** sublist){
    printf("Введите элемент, который вы хотите удалить\n");
    int number;
     if(get_number(&number)){
        printf("Неккоректный ввод");
        return;
    }
    move_to_sublist(list, sublist, number);
}