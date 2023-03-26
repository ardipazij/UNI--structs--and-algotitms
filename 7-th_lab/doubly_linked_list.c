#include "doubly_linked_list.h"
#include <stdlib.h>

Node * init(){
    Node * tmp = calloc(1, sizeof(Node));
    tmp->next = tmp;
	tmp->prev = tmp;
}

int is_empty(Node * head){
    return(head->next == head);
}
int add(Node ** head, int elem, int data, int answer){
 ;   
}
void print_forward(Node* head)
{
	Node* tmp = head->next;
	while (tmp != head)
	{
		printf(" %d ", tmp->data);
		tmp = tmp->next;
	}
    printf("\n");
}
void print_reverse(Node* head)
{
	Node* tmp = head->prev;
	while (tmp != head)
	{
        printf(" %d ", tmp->data);
		tmp = tmp->prev;
	}
    printf("\n");
}