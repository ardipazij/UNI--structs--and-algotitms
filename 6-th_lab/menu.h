#ifndef MENU_H
#define MENU_H
int get_number(int * n);
void print_info();
void status_sublist(List * list);
void add_to_list(List ** list);
void remove(List ** list, List ** sublist);
#endif