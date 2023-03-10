#include "linked_list.h"
#include <stdio.h>
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
            int i;
            for(i = 0; i < list->size; i++){
                if(list->data[i] > n){
                    for(int j = list->size; j > i; j--){
                        list->data[j] = list->data[j-1];
                    }
                    list->data[i] = n;
                    printf("Element added %d\n", list->data[i]);
                    break;
                }

            }
            if (i == list->size) {
				list->data[i] = n;
			}
        }
        list->size++;
       
    }
}
void output(Node list){
    if(is_empty(list)){
        printf("List is empty\n");
    }
    else{
        for(int i = 0; i < list.size; i++){
            printf("%d ", list.data[i]);
        }
        printf("\n");
    }
}
void search(Node list, int n){
    int flag = 0;
    for(int i = 0; i < list.size; i++){
        if(list.data[i] == n){
            printf("%d, %d pos\n", list.data[i], i+1);
            flag++;
        }else if(list.data[i] > n){
            break;
        }
    }
    if(flag == 0){
        printf("Elem isnt found\n");
    }
}
void remove_elem(Node * list, int n){
    if(is_empty(*list)){
        printf("List is empty\n");
    }
    else{
        int flag = 0;
        for(int i = 0; i < list->size; i++){
            if(list->data[i] == n){
                flag++;
                list->data[i] = '\0';
                for (int j = i; j < list->size - 1; j++) {
				    list->data[j] = list->data[j + 1];
			    }
			    list->size--;
            } else if(list->data[i] > n){
                break;
            }
        }
        if(flag == 0){
            printf("Elem isnt found\n");
        }
    }
}