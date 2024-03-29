#ifndef BINARY_TREE_H
#define BINARY_TREE_H
typedef struct Tree_node {
    int key;
    int count;
    struct Tree_node* left;
    struct Tree_node* right;
    struct Tree_node * parent;
}Tree_node;

int is_empty(Tree_node * head);
void add_to_tree(Tree_node ** head, int value);
void destroy(Tree_node ** head);
void print_in_symmetric_order(Tree_node * head, int depth);
void print_in_unsymmetric_order(Tree_node * head, int depth);
Tree_node * find_elem(Tree_node * head, int value);
void remove_elem(Tree_node ** head, int value);
Tree_node * minimum(Tree_node * head);
void print_in_minmax_order(Tree_node * head);
#endif