#include "menu.h"
#include "linked_point_list.h"
#include <stdio.h>
int main(){
    List list;
    create(&list);

    int flag = 1;
     while(flag != 0){
        int n;
        print_info();
        if(get_number(&n)){
            printf("Неверны й ввод\n");
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
                    push(&list);
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
    }
    return 0;
}