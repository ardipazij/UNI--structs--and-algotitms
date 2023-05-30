#include "menu.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int flag = 0;
    int * array = NULL;
    int size = 0;
    while(flag == 0){
        print_info();
        int n;
        if(get_number(&n)){
            printf("Ошибка ввода \n");
        }
        switch (n
        )
        {
        case 1:
            add(&array, &size);
            break;
        case 2:
            radix_sort_for_menu(array, size);
            break;
        case 3:
            bucket_sort_for_menu(array, size);
            break;
        case 4:
            generalized_bucket_sort_for_menu(array, size);
            break;
        case 5:
            destroy_array(&array, &size);
            break;
        case 0:
            flag = 1;
            break;
        default:
            printf("Неверный ввод\n");
            break;
        }
    }
    destroy_array(&array, &size);
    return 0;
}