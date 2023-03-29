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
    printf("5. Удаление элемента из списка.\n");
    printf("6. Удаление элемента из списка списков.\n");
    printf("0. Выход из программы.\n");
}

void add_to_list(Node_of_lists ** list){
    int answer, new_index, index;
    printf("Введите индекс, который хотите добавить:\n");
    if(get_number(&new_index)){
        printf("Ошибка ввода");
        return;
    }
    printf("Введите индекс, до или после которого вы хотите вставить элемент(если список пустой, введите любое число):\n");
    if(get_number(&index)){
        printf("Ошибка ввода");
        return;
    }
    if(elem_not_exist((* list), index) && !is_empty_list(*list)){
        printf("элемент не существует\n");
        return;
    }
    printf("Вы хотите вставить элемент до(0) или после(1)?");
    if(get_number(&answer)){
        printf("Ошибка ввода");
        return;
    }
    Node * list_to_add = create_node();
    add_to_node_list (list, answer, index,new_index, list_to_add);
}

void add_to_elem_list(Node_of_lists ** list){
    printf("Введите индекс списка : ");
    int index;
    if(get_number(&index)){
        printf("Ошибка ввода");
        return;
    }
    if(elem_not_exist((* list), index)){
        printf("Список не существует\n");
        return;
    }
    Node_of_lists * tmp = *list;
    while((tmp) != NULL && tmp->index != index){
        tmp = tmp->next;
    }
    Node * elem = tmp->data;
    printf("Введите элемент, который хотите добавить:\n");
    int elem_to_add;
    if(get_number(&elem_to_add)){
        printf("Ошибка ввода");
        return;
    }
    printf("Введите элемент, до или после которого вы хотите вставить элемент(если список пустой, введите любое число):\n");
    int data;
    if(get_number(&data)){
        printf("Ошибка ввода");
        return;
    }
    if(elem_node_not_exist(elem,data) && !is_empty_node(elem)){
        printf("элемент не существует\n");
        return;
    }
    printf("Вы хотите вставить элемент до(0) или после(1)?");
    int answer;
    if(get_number(&answer)){
        printf("Ошибка ввода");
        return;
    }
    add_to_node (&elem,answer, data, elem_to_add);
}
void remove_node_for_menu(Node_of_lists ** list){
    printf("Введите индекс списка, откуда хотите удалить элемент. \n");
    int index; 
    if(get_number(&index)){
        printf("Ошибка ввода");
        return;
    }
    if(elem_not_exist((* list), index)){
        printf("Список не существует\n");
        return;
    }
    Node_of_lists * tmp = *list;
    while((tmp) != NULL && tmp->index != index){
        tmp = tmp->next;
    }
    Node * elem = tmp->data; 
    printf("Введите значение, которое вы хотите удалить. \n");
    int data;
    if(get_number(&data)){
        printf("Ошибка ввода");
        return;
    }
    if(elem_node_not_exist(elem,data)){
        printf("элемент не существует\n");
        return;
    }
    remove_node(&elem, data);


}
void remove_list_for_menu(Node_of_lists ** list){
    printf("Введите индекс списка, который вы хотите удалить. \n");
    int index;
    if(get_number(&index)){
        printf("Ошибка ввода");
        return;
    }
    if(elem_not_exist((* list), index)){
        printf("Список не существует\n");
        return;
    }
    remove_node_list (list,index);
}
void find_elem(Node_of_lists ** list){
    int elem;
    int flag = 0;
    printf("Введите элемент для поиска \n");
    if(get_number(&elem)){
        printf("Элемент не найден\n");
        return;
    }
    Node_of_lists * currenr_list = (*list)->next;
    while(currenr_list != NULL){
        Node * current_node = currenr_list->data;
        current_node = current_node->next;
        while(current_node != NULL && current_node->data != elem){
            current_node = current_node->next;
        }
        if(current_node != NULL){
            printf("Элемент %d найден в списке с индексом %d\n", elem, currenr_list->index);
            flag++;
        }
        currenr_list = currenr_list->next;
    }
    if (flag == 0){
        printf("Элемент не найден. \n");
    }
}