#include "menu.h"
#include <stdio.h>
int main(){
    struct queue root;
    init(&root);
    printf("\n 1. Состояние очереди \n");
    printf("2.Добавление элемента в очередь\n");
    printf("3.Удаление элемента из очереди\n");
    printf("0. Выход из программы\n");
    int flag_command = 1;
    while(flag_command != 0){
        int n;
        if(get_number(&n)){
            printf("Неверный ввод\n");
        }
        else{
            switch(n){
                case 1:
                    status(root);
                    break;
                case 2:
                    menu_add_element(&root);
                    break;
                case 3:
                    menu_remove_elements(&root);
                    break;
                case 0:
                    flag_command = 0;
                    break;
                default:
                    printf("Неверный ввод\n");
                    break;
            }

        }
    }
}