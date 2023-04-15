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
// // Function to create a new node
// struct Node* newNode(int key) {
//     struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//     node->key = key;
//     node->count = 1;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }

// // Function to insert a key into the binary search tree
// struct Node* insert(struct Node* node, int key) {
//     if (node == NULL) {
//         return newNode(key);
//     }
//     if (key == node->key) {
//         node->count++;
//     } else if (key < node->key) {
//         node->left = insert(node->left, key);
//     } else {
//         node->right = insert(node->right, key);
//     }
//     return node;
// }

// // Function to search for a key in the binary search tree
// struct Node* search(struct Node* node, int key) {
//     if (node == NULL || node->key == key) {
//         return node;
//     }
//     if (key < node->key) {
//         return search(node->left, key);
//     }
//     return search(node->right, key);
// }

// // Function to print the binary search tree in reverse order
// void printReverse(struct Node* node) {
//     if (node == NULL) {
//         return;
//     }
//     printReverse(node->right);
//     printf("%d (%d)\n", node->key, node->count);
//     printReverse(node->left);
// }

// // Function to print the binary search tree in order
// void printInOrder(struct Node* node) {
//     if (node == NULL) {
//         return;
//     }
//     printf("%d (%d)" , node->key, node->count);
//     printInOrder(node->left);
//     printInOrder(node->right);
// }

// // Function to delete a key from the binary search tree
// struct Node* delete(struct Node* node, int key) {
//     if (node == NULL) {
//         return node;
//     }
//     if (key < node->key) {
//         node->left = delete(node->left, key);
//     } else if (key > node->key) {
//         node->right = delete(node->right, key);
//     } else {
//         if (node->count > 1) {
//             node->count--;
//         } else {
//             if (node->left == NULL) {
//                 struct Node* temp = node->right;
//                 free(node);
//                 return temp;
//             } else if (node->right == NULL) {
//                 struct Node* temp = node->left;
//                 free(node);
//                 return temp;
//             }
//             struct Node* temp = node->right;
//             while (temp->left != NULL) {
//                 temp = temp->left;
//             }
//             node->key = temp->key;
//             node->count = temp->count;
//             node->right = delete(node->right, temp->key);
//         }
//     }
//     return node;
// }

// int main() {
//     struct Node* root = NULL;
//     root = insert(root, 10);
//     root = insert(root, 5);
//     root = insert(root, 15);
//     root = insert(root, 12);
//     root = insert(root, 20);

//     // Search for a key and print its count
//     struct Node* result = search(root, 15);
//     printf("Count of key 15: %d\n", result->count);

//     // Insert a new key
//     root = insert(root, 10);

//     // Print the binary search tree in reverse order
//     printf("Binary search tree in reverse order:\n");
//     printReverse(root);

//     // Print the binary search tree in order
//     printf("Binary search tree in order:\n");
//     printInOrder(root);
//     printf("\n");

//     // Delete a key
//     root = delete(root, 5);

//     // Print the binary search tree in order after deletion
//     printf("Binary search tree in order after deletion:\n");
//     printInOrder(root);
//     printf("\n");

//     return 0;
// }