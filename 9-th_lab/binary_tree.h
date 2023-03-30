#ifndef BINARY_TREE_H
#define BINARY_TREE_H
typedef struct Tree_node{
    int data;
    struct Tree_node * right;
    struct Tree_node * left;
}Tree_node;
void destroy(Tree_node ** head);
#endif