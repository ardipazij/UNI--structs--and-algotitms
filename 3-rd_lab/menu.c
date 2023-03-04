#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "menu.h"

void push(DblLinkedList ** list){
    int push_number = (rand() % 3);
    printw("Add %d element(s)\n", push_number);
    for(int j = 0; j <= push_number; j++){
        char ex[4];
        for(int i = 0; i < 3; i++){
            ex[i] = 65 + rand() % 26;
        }
        ex[3] = '\0';
        pushBack(list, ex);
        }
}

void pop(DblLinkedList ** list){
    int pop_number = (rand() % 3) + 1;
    printw("Remove %d element(s)\n", pop_number);
    for(int i = 0; i < pop_number; i++){
        if((*list)->head != NULL){
            char * tmp = popFront(list);
            printw("%s\n", tmp);
            free(tmp);
        }
        else{
            printw("List is empty\n");
            break;
        }
    }    
}
void input (int * flag){
    char c = getch();
    switch(c){
        case 'q':
            *flag = 1;
            break;

    }
}