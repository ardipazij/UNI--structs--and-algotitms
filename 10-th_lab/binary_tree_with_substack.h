#ifndef BINARY_TREE_WITH_SUBSTACK_H
#define BINARY_TREE_WITH_SUBSTACK_H
typedef struct Tree_node{
    int data;
    struct Tree_node * right;
    struct Tree_node * left;
}Tree_node;
typedef struct Stack{
    Tree_node * prev;
    struct Stack * next;
    int depth;
}Stack;
Tree_node * create(int data);
void destroy(Tree_node ** head);
void add_to_tree(Tree_node ** head, int numbers);
void print_in_symmetric_order(Tree_node * head, int depth);
void print_in_inverse_symmetric_order(Tree_node * head, int depth);
void print_in_direct_order(Tree_node * head, int depth);
void print_in_simmetric_order_with_stack(Tree_node * head);
#endif