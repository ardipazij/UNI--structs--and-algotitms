#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"
#include <unistd.h>
#include <ncurses.h>
void input (int * flag){
    char c = getch();
    switch(c){
        case 'q':
            *flag = 1;
            break;

    }
}
int main(){
    DblLinkedList * list = create_list();
    int flag = 0;
    initscr();
    nodelay(stdscr, TRUE);
    while(flag == 0){
        system("/bin/stty raw");
        
        int c = rand();
        if(c % 2 == 0){
            int push_number = (rand() % 3) + 1;
            printw("Add %d element(s)\n", push_number);
            for(int j = 0; j < push_number; j++){
                char ex[4];
                for(int i = 0; i < 3; i++){
                ex[i] = 65 + rand() % 25;
                }
                ex[3] = '\0';
              
                pushBack(&list, ex);
            }
        }
        else{
            int pop_number = (rand() % 3) + 1;
            printw("Remove %d element(s)\n", pop_number);
            for(int i = 0; i < pop_number; i++){
                if(list->head != NULL){
                    char * tmp = popFront(&list);
                    printw("%s\n", tmp);
                    free(tmp);
                }
                else{
                    printw("List is empty\n");
                    break;
                }
            }
        
            
        }
        output(list);
        input(&flag);
        usleep(100000);
        clear();


    }
    system("/bin/stty cook");
    endwin();
    destroy(&list);
    return 0;
}