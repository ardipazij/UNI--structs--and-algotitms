#include "menu.h"
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    int flag = 0;
    Tree_node * root = NULL;
    while(flag == 0){
        print_info();
        int n;
        if(get_number(&n)){
            printf("Ошибка ввода \n");
        }
        switch (n)
        {
        case 1:
            add(&root);
            break;
        case 2:
            find(root);
            break;
        case 3:
            output(root);
            break;
        case 4:
            delete_node(&root);
            break;
        case 5:
            destroy_tree(&root);
            break;
        case 0:
            flag = 1;
            break;
        default:
            printf("Неверный ввод\n");
            break;
        }
    }
    destroy(&root);
    return 0;
}