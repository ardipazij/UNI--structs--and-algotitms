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
        case 3:
            add_to_list(&list);
            break;
        case 4:
            add_to_elem_list(&list);
            break;
        case 5:
            remove_node_for_menu(& list);
            break;
        case 6:
            remove_list_for_menu(& list);
            break;
        default:
            break;
        }
    }
    destroy_node_list(&list);
    return 0;
}