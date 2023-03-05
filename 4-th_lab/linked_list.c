#include "linked_list.h"

int is_empty(Node list){
    return (list.size == 0);
}
int is_full(Node list){
    return (list.size == NMAX - 1);
}
int get_number(int * n){
    int flag_error = 0;
    if(scanf("%d", n)!= 1){
        flag_error = 1;
        scanf("%*[^\n]");
    }
    return flag_error;
}
void push(Node * list){
    if (is_full(*list)){
        printf("List is full\n");
        return;
    }
    int n;
    if(get_number(&n)){
        printf("Number's error\n");
    }
    else{
        if(is_empty(*list)){
            list->data[0] = n;
        }
        else{
            for(int i = 0; i < list->size; i++){
                if(list->data[i] > n){
                    for(int j = list->size; j > i; j--){
                        list->data[j] = list->data[j-1];
                    }
                    list->data[i] = n;
                    break;
                }
            }
        }
        list->size++;
    }
}