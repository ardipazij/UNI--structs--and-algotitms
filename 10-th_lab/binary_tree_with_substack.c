#include "binary_tree_with_substack.h"
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
void print_in_simmetric_order_with_stack(Tree_node * head){
    Stack * root = calloc(1, sizeof(Stack));
    root->depth = -1;
    root->prev = head;
    root->next = NULL;
    int depth = 0;
    Tree_node * current = head;
    while(current != NULL || depth >= 0){
        while (current != NULL)
		{
			Stack* node = calloc(1, sizeof(Stack));
			node->depth = depth;
			node->prev = current;
			node->next = root;
			root = node;
			current = current->left;
			depth += 4;
		}
        depth = root->depth;

		current = root->prev;
		Stack* temporary = root;
		root = root->next;
		free(temporary);

		for (int i = 0; i < depth; i++){
            printf(" ");
        }
        printf("%d\n", current->data);

		current = current->right;
		depth += 4;
    }
}