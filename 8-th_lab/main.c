#include <stdio.h>
#include "list_of_lists.h"
#include "menu.h"

int main(){
    Node_of_lists * list = create_node_of_lists();
    int flag = 0;
    while(flag == 0){
        print_info();
        int n;
        if(get_number(&n)){
            printf("Input error\n");
        }
        switch (n)
        {
        case 1:
            print_node_list(list);
            break;
        case 0:
            flag = 1;
            break;
        default:
            break;
        }
    }
    destroy_node_list(&list);
    return 0;
}