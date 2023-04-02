#include "menu.h"
#include "binary_tree_with_substack.h"
#include <stdio.h>

int main(){
    int flag = 0;
    Tree_node * root;
    while(flag == 0){
        print_info();
        int n;
        if(get_number(&n)){
            printf("Ошибка ввода \n");
        }
        switch (n)
        {
        case 1:
            //add(&root);
            break;
        case 2:
            output(root);
            break;
        case 3:
            destroy(&root);
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