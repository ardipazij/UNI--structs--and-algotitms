#include "binary_tree.h"
#ifndef MENU_H
#define MENU_H
int get_number(int * n);
void print_info();
void add(Tree_node ** head);
void output(Tree_node * head);
void find(Tree_node * head);
void delete_node(Tree_node ** head);
void destroy_tree(Tree_node **  head);
#endif