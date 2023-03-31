#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
void destroy(Tree_node ** head)
{
	if ((*head) == NULL)
		return;
    Tree_node * left_tree = (*head)->left;
    Tree_node * right_tree = (*head)->right;
	destroy(&left_tree);
	destroy(&right_tree);
	free(*head);
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
        return;
    }
    int left = numbers / 2;
    int right = numbers - left - 1;
    int data = rand() % 99;
    Tree_node * new_tree_node = create(data);
    //printf("%d\n", new_tree_node->data);
    Tree_node * left_tree;
    new_tree_node->left = left_tree;
    Tree_node * right_tree;
    new_tree_node->right = right_tree;
    add_to_tree(&left_tree, left);
    add_to_tree(&right_tree, right);
    (*head) = new_tree_node;
}

void print_in_symetry_order(Tree_node * head, int depth){
    if(head == NULL){
        return;
    }
    print_in_symetry_order(head->left, depth + 4);
    while(depth != 0){
        printf(" ");
        depth--;
    }
    printf("%d",head->data );
    print_in_symetry_order(head->right, depth + 4);
}