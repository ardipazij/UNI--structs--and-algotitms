#include <stdio.h>
#include "list_of_lists.h"
#include "menu.h"

int main(){
    Node_of_lists * list = create_node_of_lists();
    int flag = 0;
    while(flag == 0){
        int n;
        if(get_number(&n)){
            printf("Input error\n");
        }
        print_info();
        switch (n)
        {
        case 1:
            print_node_list(list);
            break;
        
        default:
            break;
        }
    }
}