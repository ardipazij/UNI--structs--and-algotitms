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