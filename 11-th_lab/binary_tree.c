#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

Tree_node * create(int data){
    Tree_node * tmp = calloc(1, sizeof(Tree_node));
    tmp->data = data;
    tmp->left = NULL;
    tmp-> right = NULL;
    return (tmp);
}

void destroy(Tree_node ** head)
{
	if ((*head) == NULL)
		return;
    Tree_node * tmp = (*head);
	destroy(&tmp->left);
	destroy(&tmp->right);
	free(*head);
    (*head) = NULL;
}

void print_in_symmetric_order(Tree_node * head, int depth){
    if(head == NULL){
        return;
    }
    print_in_symmetric_order(head->left, depth + 5);
    for(int i = 0; i < depth; i++){
        printf(" ");
    }
    printf("%d\n",head->data );
    print_in_symmetric_order(head->right, depth + 5);
}

void print_in_inverse_symmetric_order(Tree_node * head, int depth){
    if(head == NULL){
        return;
    }
    print_in_inverse_symmetric_order(head->right, depth + 5);
    for(int i = 0; i < depth; i++){
        printf(" ");
    }
    printf("%d\n",head->data);
    print_in_inverse_symmetric_order(head->left, depth + 5);
}

void print_in_direct_order(Tree_node * head, int depth){
    if(head == NULL){
        return;
    }
    for(int i = 0; i < depth; i++){
        printf(" ");
    }
    printf("%d\n",head->data);
    print_in_direct_order(head->left, depth + 5);
    print_in_direct_order(head->right, depth + 5);
}

void find_in_tree(Tree_node * head, int value, Tree_node ** result, int * status){
    if(head == NULL || (*status) == 1){
        return;
    }
    if(head->data != value){
        find_in_tree(head->left, value, result, status);
        find_in_tree(head->right, value, result, status);
    }
    else{
        *status = 1;
        (*result) = head;
    }
}
void add_to_node(Tree_node ** current, int value){
    if((*current)->left != NULL && (*current)->right != NULL){
        printf("Добавить значение нельзя\n");
        return;
    }
    Tree_node * new_node = create(value);
    if((*current)->left != NULL && (*current)->right == NULL){
        (*current)->right = new_node;
        return;
    }
    else if ((*current)->left == NULL && (*current)->right != NULL){
        (*current)->left = new_node;
        return;
    }
    else {
        int answer;
        printf("Вы хотите добавить значение в левую ветку(0), или в правую(1)?\n");
        if(scanf("%d", &answer)!= 1 && (answer == 1 || answer == 0)){
            printf("Неверный ввод\n");
            scanf("%*[^\n]");
            free(new_node);
            return;
        }
        if (answer == 1){
            (*current)->right =  new_node;
        }
        else{
            (*current)->left = new_node;
        }
    }
    printf("Новое значение добавлено\n");
}