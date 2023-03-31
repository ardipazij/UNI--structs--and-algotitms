#include "menu.h"
#include "binary_tree.h"
#include <stdio.h>

int main(){
    printf("Введите количество элементов дерева(0, 99): \n");
    int n;
    if(scanf("%d", &n) != 1){
        printf("n/a\n");
        return 0;
    }
    Tree_node * root;
    add_to_tree(&root, n);
    //printf("%d", root->data);
    print_in_symetry_order(root, 0);
    destroy(&root);
    return 0;
}