#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
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
Tree_node * create(int data){
    Tree_node * tmp = calloc(1, sizeof(Tree_node));
    tmp->data = data;
    tmp->left = NULL;
    tmp-> right = NULL;
    return (tmp);
}
void add_to_tree(Tree_node ** head, int numbers){
    if(numbers == 0){
        (*head) = NULL;
        return;
    }
    int left = numbers / 2;
    int right = numbers - left - 1;
    int data = rand() % 99;
    Tree_node * new_tree_node = create(data);
    //printf("%d\n", new_tree_node->data);
    add_to_tree(&new_tree_node->left, left);
    add_to_tree(&new_tree_node->right, right);
    (*head) = new_tree_node;
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