#include <stdio.h>
#include "menu.h"
void status(Node list){
    if(is_empty(list)){
        printf("List is empty\n");
        return;
    } else{
        output(list);
    }
}
void find(Node list){
    int number;
    if(get_number(&number)){
        printf("Number's error\n");
        return;
    } else{
        search(list, number);
    }
}
void add_elem(Node * list){
    push(list);
}
void delete_elem(Node * list){
    int number;
    if(get_number(&number)){
        printf("Number's error\n");
        return;
    } else{
        remove_elem(list, number);
    }
}
void delete_list(Node * list){
    while(list->size != 0){
        list->data[list->size - 1] = '\0';
        list->size--;
    }
}
void printf_info(){
    printf("1. Вывод на экран информации о списке\n");
    printf("2. Поиск элемента с заданной информационной частью\n");
    printf("3. Добавление нового элемента\n");
    printf("4. Удаление элемента\n");
    printf("0. Выход из программы\n");
}