#include <stdio.h>
#include "static_queue.h"

void init(queue * root){
    root->back = -1;
    root->front = -1;
}
int is_empty(queue root){
    return root.front;
}
int is_full(queue root){
    return ((root.front == root.back + 1) || (root.front == 0 && root.back == SIZE - 1));
}
void add_element(queue * root, int data_elem){
    if(is_full(* root)){
        printf("Queue is full \n");
    }
    else{
        if(root->front == -1)
            root-> front = 0;

        root->back = (root->back + 1) % SIZE;
        root->data[root->back] = data_elem;

    }
}
int remove_element(queue * root){
    int data_elem = root->data[root->front];
    if (root->front == root->back){
        root->front = -1;
        root->back = -1;
    }
    else{
        root->front = (root->front + 1) % SIZE;
    }
    return data_elem;
}
void output(queue root){
    for(int i = root.front; i != root.back; (i+1)%SIZE){
        printf("%d\n", root.data[i]);
    }
}