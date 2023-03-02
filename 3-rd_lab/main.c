#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"
#include <ncurses.h>
void input (int * flag){
    char c = getc();
    switch(c){
        case 'q':
            *flag = 1;
            break;

    }
}
int main(){
    DblLinkedList * list = create();
    int flag = 0;
    initsrc();
    nodelay(stdscr, TRUE);
    while(flag == 0){
        system("/bin/stty raw");
        char ex[3];
        for(int i = 0; i < 3; i++){
            ex[i] = 65 + rand() % 25;
        }
        int c = rand() % 2;
        if(c == 0){
            int push_number = 3;
        }
        else{
            int pop_number = 3;
        }
        input(&flag);
        sleep(100);

    }
    system("/bin/stty cook");
    endwin();
    destroy(&list);
    return 0;
}