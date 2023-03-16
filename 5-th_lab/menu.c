#include <stdio.h>
#include "linked_point_list.h"
#include "menu.h"

void print_info(){
    printf("1. Вывести на экран информацию о списке\n");
    printf("2. Поиск элемента по значению \n");
    printf("3. Добавить элемент в список\n");
    printf("4. Удалить элемент из списка\n");
    printf("0. Выйти из программы\n");
}
int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
}
void status(List list){
    if(is_empty(list)){
        printf("Список пуст\n");
        return;
    }
    output(list);
}