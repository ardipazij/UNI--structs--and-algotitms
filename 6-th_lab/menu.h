#ifndef MENU_H
#define MENU_H
#include "linked_dynamic_list.h"
int get_number(int * n);
void print_info();
void status_sublist(List * list);
void add_to_list(List ** list);
void remove_elem(List ** list, List ** sublist);
#endif