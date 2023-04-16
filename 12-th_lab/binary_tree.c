#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
int is_empty(Tree_node * head){
    return (head == NULL); 
}

void add_to_tree(Tree_node ** head, int value){
    Tree_node * parent = NULL;
    Tree_node * current = *head;
    while(current != NULL){
        parent = current;
        if(value < parent->key){
            current = current->left;
        }
        else if(value > parent->key){
            current = current->right;
        }
        else{
            current->count++;
            return;
        }
    }
    Tree_node * new_node = calloc(1, sizeof (Tree_node));
    new_node->key = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = parent;
    new_node->count = 1;
    if(parent == NULL){
        *head = new_node;
        return;
    }
    else if(parent->key < new_node->key){
        parent->right = new_node;
    }
    else{
         parent->left = new_node;
    }
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
    printf("%d (%d)\n",head->key, head->count);
    print_in_symmetric_order(head->right, depth + 5);
}

Tree_node * find_elem (Tree_node * head, int value){
    if(head == NULL || head->key == value){
        return head;
    }
    if (head->key < value){
        return find_elem(head->right, value);
    }
    else{
        return find_elem(head->left, value);
    }
}
Tree_node * minimum(Tree_node * head){
    while(head->left != NULL){
        head = head->left;
    }
    return head;
}
void remove_elem(Tree_node ** head, int value){
    Tree_node * current = find_elem(*head, value);
    if (current == NULL){
        printf("Элемента с данным ключом не существует\n");
        return;
    }
    if (current->count > 1){
        current->count--;
        return;
    }
    if (current->left == NULL && current->right == NULL){
        if(current->parent == NULL){
            free(current);
            (*head) = NULL;
            return;
        }
        if(current->parent->left == current){
            current->parent->left = NULL;
        }
        else{
             current->parent->right = NULL;
        }
        free(current);
        return;
    }
    else if(current->left == NULL){
        if(current->parent == NULL){
            current->right->parent = NULL;
            (*head) = current->right;
        }
        else{
            current->right->parent = current->parent;
            if(current == current->parent->left){
                current->parent->left = current->right;
            }
            else{
                current->parent->right = current->right;
            }
        }
    }
    else if(current->right == NULL){
        if(current->parent == NULL){
            current->left->parent = NULL;
            (*head) = current->left;
        }
        else{
            current->left->parent = current->parent;
            if(current == current->parent->left){
                current->parent->left = current->left;
            }
            else{
                current->parent->right = current->left;
            }
        }
    }
    else{
        Tree_node * new_node = minimum(current->right);
        if(new_node->parent != current){
            if (new_node->parent->left == new_node){
                new_node->parent->left = new_node->right;
            } else {
                new_node->parent->right = new_node->right;
            }
            if(new_node->right != NULL){
                new_node->right->parent = new_node->parent;
            }
            new_node->right = current->right;
            new_node->right->parent = new_node;
        }
        if(current->parent == NULL){
            (*head) = new_node;
        }
        else if (current->parent->left == current){
            current->parent->left = new_node;
        } else {
            current->parent->right = new_node;
        }
        //new_node->parent = current->parent;
		new_node->left = current->left;
		new_node->left->parent = new_node;
        //
        }
    free(current);
}

void print_in_minmax_order(Tree_node * head){
    if(head == NULL){
        return;
    }
    print_in_minmax_order(head->left);
    printf("%d (%d) ",head->key, head->count);
    print_in_minmax_order(head->right);
}