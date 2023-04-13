#ifndef BINARY_TREE_H
#define BINARY_TREE_H
typedef struct Tree_node {
    int key;
    int count;
    struct Tree_node* left;
    struct Tree_node* right;
    struct Tree_node * parent;
}Tree_node;

int is_empty(Tree_node * root);

void add_to_tree(Tree_node ** root, int value);
#endif