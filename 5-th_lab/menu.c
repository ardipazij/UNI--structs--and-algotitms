#include <stdio.h>
#include "linked_point_list.h"
#include "menu.h"

void print_info(){
    printf("1. Вывести на экран информацию o списке\n");
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
void find(List list){
    int n;
    if(get_number(&n)){
        printf("Неккокректный ввод\n");
        return;
    }
    int index = find_elem(list, n); 
    if(index == -1){
        printf("Элемент не найден\n");
    } else{
        printf("Найден элемент %d\n", list.array[index].data);
    }
}
void delete_elem(List * list){
    int n;
    if(get_number(&n)){
        printf("Неккоректный ввод\n");
        return;
    }
    remove_element(list, n);
}