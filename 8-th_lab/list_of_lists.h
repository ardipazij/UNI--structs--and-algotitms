#ifndef LIST_OF_LISTS
#define LIST_OF_LISTS
typedef struct Node{
    int data;
    struct Node * next; 
    
}Node;

typedef struct Node_of_lists{
    int index;
    struct Node * data;
    struct Node_of_lists * next; 
    
}Node_of_lists;
#endif