#include <stdio.h>
#include "menu.h"
#include "doubly_linked_list.h"

int main(){
    Node * head = init();
    int flag = 0;
    while(flag == 0){
        print_list();
        int n;
        if(get_number(&n)){
            printf("Неккоректный ввод.\n");
        }
        switch (n)
        {
        case 1:
            output(head);
            break;
        case 2:
            find(head);
            break;
        case 3:
            add_elem(&head);
            break;
        case 4:
            remove_elem(&head);
            break;
        case 0:
            flag = 1;
            break;
        default:
            printf("Ошибка ввода\n");
            break;
        }
    }
//    destroy(&head);
    return 0;
}