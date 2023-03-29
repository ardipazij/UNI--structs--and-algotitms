#include "list_of_lists.h"
#ifndef MENU_H
#define MENU_H
void print_info();
int get_number(int * n);
void add_to_list(Node_of_lists ** list);
void add_to_elem_list(Node_of_lists ** list);
void remove_list_for_menu(Node_of_lists ** list);
void remove_node_for_menu(Node_of_lists ** list);
void find_elem(Node_of_lists ** list);
#endif