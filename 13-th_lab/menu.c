#include "menu.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
}
void print_info(){
    printf("1. Создание массива \n");
    printf("2. Сортировка пузырьком \n");
    printf("3. Сортировка выбором \n");
    printf("4. Сортировка заменой\n");
    printf("5. Удаление массива \n");
    printf("0. Выход из программы\n");
}
int numbers_of_element(){
    int n;
    printf("Введите количество элементов\n");
    if(get_number(&n) || n < 1){
        printf("Ошибка ввода \n");
        return 0;
    }
    return n;
}
int * create_array(int n){
    if(n == 0){
        printf("Ошибка ввода\n");
        return NULL;
    }
    int * array = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        int r = rand() % 100;
        array[i] = r;
    }
    return array;
}
void destroy_array(int ** array, int * size){
    free(*array);
    (*size) = 0;
    *array = NULL;

}

void buble_sort_for_menu(int * items, int n){
    if (n == 0){
        printf("Ошибка обработки массива \n");
        return;
    }
    buble_sort(items, n);
}

void add(int ** array, int * size){
    (*size) = numbers_of_element();
    (*array) = create_array(*size);
}