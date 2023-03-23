#include <stdio.h>
#include "menu.h"
#include "linked_dynamic_list.h"
int main(){
    List * list = create();
    List * sublist = create();
    int flag = 1;
     while(flag != 0){
        int n;
        print_info();
        if(get_number(&n)){
            printf("Неверный ввод\n");
        }
        else{
            switch(n){
                case 1:
                    output(list);
                    break;
                case 2:
                    status_sublist(sublist);
                    break;
                case 3:
                    add_to_list(&list);
                    break;
                case 4:
                    remove_elem(&list, &sublist);
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
    destroy(&list);
    destroy(&sublist);
    return 0;
}