#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"
#include "menu.h"
#include <unistd.h>
#include <ncurses.h>

int main(){
    DblLinkedList * list = create_list();
    int flag = 0;
    initscr();
    nodelay(stdscr, TRUE);
    while(flag == 0){
        system("/bin/stty raw");
        
        int c = rand();
        if(c % 2 == 0){
            push(&list);
        }   else{
            pop(&list);
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