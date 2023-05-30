#include "menu.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    printf("2. Поразрядная сортировка \n");
    printf("3. Простейшая карманная сортировка\n");
    printf("4. Обобщенная карманная сортировка\n");
    printf("5.Удаление массива\n");
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
int * create_array(int n, int uniq_values){
    if(n == 0){
        printf("Ошибка ввода\n");
        return NULL;
    }
    int * arr = calloc(n, sizeof(int));
    if(uniq_values == 1){
        int * used = calloc(n, sizeof(int));
        for(int i = 0; i < n; i++){
            used[i] = 0;
        }
        srand(time(NULL)); // инициализируем генератор случайных чисел

        for (int i = 0; i < n; i++) {
        int unique = 0; // флаг для проверки уникальности числа
        while (!unique) {
            int rand_num = rand() % n; // генерируем случайное число
            if (!used[rand_num]) { // если число еще не использовалось
                used[rand_num] = 1; // отмечаем его как использованное
                arr[i] = rand_num; // записываем его в массив
                unique = 1; // устанавливаем флаг уникальности в 1, чтобы выйти из цикла
            }
        }
    }
    }
    else if(uniq_values == 0){
        int * temp = calloc(n, sizeof(int));
        for (int i = 0 ; i < n + rand() % n; i++) {
			temp[i] = rand() % n;
		}
        for (int i = 0; i < n; i++) {
            int r = i + rand() % (n - i);
            arr[i] = temp[r];
            temp[r] = temp[i];
        }
        free(temp);
    }
    else if(uniq_values == 2){
        for (int i = 0; i < n; i++){
            arr[i] = rand() % 100;
        }
    }
    return arr;
}
void add(int ** array, int * size){
    if((*size) != 0){
        printf("Сначала удалите старый массив \n");
        return;
    }
    int uniq_values;
    printf("Вы хотите создать уникальный массив для простейшей краманной сортировки(1), обычный массив co случайными значениями(0) или массив случайных чисел(2)?\n");
    if(get_number(&uniq_values) || (uniq_values != 1 && uniq_values != 0 && uniq_values != 2)){
        printf("Ошибка ввода\n");
        return;
    }
    (*size) = numbers_of_element();
    (*array) = create_array(*size, uniq_values);
}

void destroy_array(int ** array, int * size){
    free(*array);
    (*size) = 0;
    *array = NULL;

}
void radix_sort_for_menu(int * items, int n){
    if (n == 0){
        printf("Ошибка обработки массива \n");
        return;
    }
    radix_sort(items, n);
}

void bucket_sort_for_menu(int * items, int n){
    if (n == 0){
        printf("Ошибка обработки массива \n");
        return;
    }
    int command;
    printf("Введите способ сортировки:\n0. Без вспомогательного массива\n1. С вспомогательным массивом\n");
    if(get_number(&command) || (command != 1 && command != 0)){
        printf("Ошибка ввода\n");
        return;
    }
    bucket_sort(items, n, command);
}
void generalized_bucket_sort_for_menu(int * items, int n){
    if (n == 0){
        printf("Ошибка обработки массива \n");
        return;
    }
    genericBucketSort(items, n);
}