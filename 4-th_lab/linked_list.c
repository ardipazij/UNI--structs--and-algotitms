#include "linked_list.h"

int is_empty(Node list){
    return (list.size == 0);
}
int is_full(Node list){
    return (list.size == NMAX - 1);
}