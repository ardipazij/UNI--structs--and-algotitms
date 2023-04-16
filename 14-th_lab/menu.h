#ifndef MENU_H
#define MENU_H
int get_number(int * n);
void print_info();
void add(int ** array, int * size);
void buble_sort_for_menu(int * items, int n);
void selection_sort_for_menu(int * items, int n);
void insert_sort_for_menu(int * items, int n);
void heap_sort_for_menu(int * items, int n);
void quick_sort_for_menu(int * items, int n);
void destroy_array(int ** n, int * size);
#endif