#include <stdio.h>
#include "menu.h"
void status(Node list){
    if(is_empty(list)){
        printf("List is empty\n");
        return;
    } else{
        output(list);
    }
}
void find(Node list){
    int number;
    if(get_number(&number)){
        printf("Number's error\n");
        return;
    } else{
        search(list, number);
    }
}
void add_elem(Node * list){
    push(list);
}
void delete_elem(Node * list){
    int number;
    if(get_number(&number)){
        printf("Number's error\n");
        return;
    } else{
        remove(list, number);
    }
}
void delete_list(Node * list){
    while(list->size != 0){
        list->data[list->size - 1] = '\0';
        list->size--;
    }
}