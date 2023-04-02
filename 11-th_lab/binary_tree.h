#ifndef BINARY_TREE_H
#define BINARY_TREE_H
typedef struct Tree_node{
    int data;
    struct Tree_node * right;
    struct Tree_node * left;   
}Tree_node;
Tree_node * create(int data);
void destroy(Tree_node ** head);
void print_in_symmetric_order(Tree_node * head, int depth);
void print_in_inverse_symmetric_order(Tree_node * head, int depth);
void print_in_direct_order(Tree_node * head, int depth);
void find_in_tree(Tree_node * head, int value, Tree_node ** result, int * status);
void add_to_node(Tree_node ** current, int value);
#endif