#ifndef MENU_H
#define MENU_H
int get_number(int * n);
void generalized_bucket_sort_for_menu(int * items, int n);
void print_info();
void add(int ** array, int * size);
void radix_sort_for_menu(int * items, int n);
void bucket_sort_for_menu(int * items, int n); 
void destroy_array(int ** n, int * size);
#endif