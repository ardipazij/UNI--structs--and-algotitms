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
int is_empty_list(Node_of_lists * list);
int is_empty_node(Node * list);
Node * create_node();
Node_of_lists * create_node_of_lists();
void add_to_node (Node ** list, int answer, int number, int number_to_add);
void add_to_node_list (Node_of_lists ** list, int answer, int index, int new_index, Node * list_to_add);
void remove_node(Node ** list, int number);
void remove_node_list (Node_of_lists ** list, int index);
void destroy_node (Node ** list);
void destroy_node_list (Node_of_lists ** list);
void print_node_list(Node_of_lists * list);
int elem_not_exist(Node_of_lists * head, int data);
int elem_node_not_exist(Node * head, int data);
#endif