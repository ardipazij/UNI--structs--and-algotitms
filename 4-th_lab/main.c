#include "menu.h"
#include <stdio.h>
int main(){
    Node list;
    int flag = 1;
    while(flag != 0){
        int n;
        if(get_number(&n)){
            printf("Неверный ввод\n");
        }
        else{
            switch(n){
                case 1:
                    status(list);
                    break;
                case 2:
                    find(list);
                    break;
                case 3:
                    add_elem(&list);
                    break;
                case 4:
                    delete_elem(&list);
                    break;
                case 0:
                    flag = 0;
                    break;
                default:
                    printf("Неверный ввод\n");
                    break;
            }

        }
        printf_info();
    }
    return 0;
}